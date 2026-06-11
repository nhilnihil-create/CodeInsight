#include <iostream>
#include <string>
#include <vector>

using namespace std;

class point {
public:
	int x, y;
	point() {}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

class list_node {
public:
	list_node *prev, *next;
	point data;
	list_node(list_node *_prev, list_node *_next, point _data) {
		prev = _prev;
		next = _next;
		data = _data;
	}
};

class list {
public:
	list_node *front, *back;
	list() {
		front = new list_node(0, 0, point());
		back = new list_node(front, 0, point());
		front->next = back;
	}
	~list() {
		list_node *node = front;
		while (node) {
			list_node *next = node->next;
			delete node;
			node = next;
		}
	}
	list_node* insert_next(list_node *node, point data) {
		list_node *pre_next = node->next;
		node->next = new list_node(node, pre_next, data);
		pre_next->prev = node->next;
		return node->next;
	}
	list_node* push_front(point data) {
		return insert_next(front, data);
	}
	list_node* push_back(point data) {
		return insert_next(back->prev, data);
	}
	list_node* get_first() {
		return front->next;
	}
	list_node* get_last() {
		return back->prev;
	}
	void remove(list_node *node) {
		list_node *prev = node->prev;
		list_node *next = node->next;
		prev->next = next;
		next->prev = prev;
		delete node;
	}
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(vector<string> &cell) {
	int h = cell.size(), w = cell[0].size();
	list q;
	vector<vector<int>> d(h, vector<int>(w, -1));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (cell[i][j] == '#') {
				q.push_back(point(i, j));
				d[i][j] = 0;
			}
		}
	}
	int max_d = 0;
	while (q.get_first() != q.back) {
		point p = q.get_first()->data;
		q.remove(q.get_first());
		max_d = d[p.x][p.y];
		for (int i = 0; i < 4; ++i) {
			point to(p.x + dx[i], p.y + dy[i]);
			if (to.x < 0 || to.y < 0 || to.x >= h || to.y >= w) continue;
			if (d[to.x][to.y] != -1) continue;
			d[to.x][to.y] = d[p.x][p.y] + 1;
			q.push_back(to);
		}
	}
	return max_d;
}

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> cell(h, string());
	for (int i = 0; i < h; ++i) cin >> cell[i];
	cout << bfs(cell) << endl;
	return 0;
}