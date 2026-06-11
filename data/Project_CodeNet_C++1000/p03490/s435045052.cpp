#include <iostream>
#include <vector>
#include <stack>
#include <string>
constexpr int MaxOrderCount = 8000;
class Robot_position {
	bool position[MaxOrderCount * 2 + 1];
public:
	Robot_position() { for (auto &p : position) p = false; position[MaxOrderCount] = true; }
	void move(int move_count) {
		std::stack<int> stack;
		for (auto i = 0; i < MaxOrderCount * 2 + 1; ++i) {
			if (position[i]) {
				position[i] = false;
				stack.push(i);
			}
		}
		for (auto s = stack.top(); stack.size() != 0;) {
			s = stack.top();
			stack.pop();
			if (move_count <= s) {
				position[s - move_count] = true;
			}
			if (s + move_count <= MaxOrderCount * 2) {
				position[s + move_count] = true;
			}
		}
	}
	bool operator()(int pos) const {
		return position[pos + MaxOrderCount];
	}
};
enum class Axis : char{
	X, Y
};
void switch_axis(Axis &axis) {
	switch (axis) {
	case Axis::X:axis = Axis::Y; break;
	case Axis::Y:axis = Axis::X; break;
	}
}
int main() {
	std::string s;
	std::cin >> s;
	int x, y;
	std::cin >> x >> y;
	Robot_position x_pos, y_pos;
	Axis axis = Axis::X;
	int move_count = 0;
	int bias = 0;
	for (; bias < s.length() && s[bias] == 'F'; ++bias) --x;
	for (; bias < s.length(); ++bias) {
		switch (s[bias]) {
		case 'T':
			switch (axis) {
			case Axis::X:
				x_pos.move(move_count);
				break;
			case Axis::Y:
				y_pos.move(move_count);
				break;
			}
			move_count = 0;
			switch_axis(axis); break;
		case 'F': ++move_count; break;
		}
	}
	switch (axis) {
	case Axis::X:
		x_pos.move(move_count);
		break;
	case Axis::Y:
		y_pos.move(move_count);
		break;
	}
	if (x_pos(x) && y_pos(y)) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
}