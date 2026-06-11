#include <iostream>
#include <map>  
#include <algorithm>
#include <string>
#include <utility>
#include <deque>
#include <vector>
#include <set>
#include <numeric>

bool dp_search(std::vector<int>& inst, int target, bool is_start) {
	
	int max_point = std::accumulate(inst.begin(), inst.end(), 0);

	if (std::abs(target) > max_point) return false;
	if (inst.size() <= 0) {
		if (target == 0) return true;
		else return false;
	}
	std::vector<std::vector<bool>> dp(inst.size(), (std::vector<bool>((max_point + 1)*2, false)));
	
	
	dp[0][max_point + inst[0]] = true;
	if (is_start == false) dp[0][max_point - inst[0]] = true;
	
	
	for (int i = 1; i < inst.size(); i++) {
		for (int j = -max_point; j <= max_point; j++) {
			if (max_point + j - inst[i] >= 0)
				dp[i][max_point + j] = dp[i][max_point + j] | dp[i - 1][max_point + j - inst[i]];
			if (max_point + j + inst[i] < (max_point + 1) * 2)
				dp[i][max_point + j] = dp[i][max_point + j] | dp[i - 1][max_point + j + inst[i]];
		}
	}
	return dp[inst.size() - 1][max_point + target];
}

int main() {
	std::string instruction;
	std::vector<int> X_inst, Y_inst;
	int x_target, y_target;
	std::cin >> instruction;
	std::cin >> x_target;
	std::cin >> y_target;

	int counter = 0;
	int is_x_direct = true;
	for (int i = 0; i < instruction.length(); i++) {
		if (instruction[i] == 'T') {

			if (is_x_direct) X_inst.push_back(counter);
			else Y_inst.push_back(counter);

			is_x_direct = !is_x_direct;
			counter = 0;
		}
		else {
			counter++;
		}	
	}

	if (is_x_direct) X_inst.push_back(counter);
	else Y_inst.push_back(counter);

	bool result = dp_search(X_inst, x_target, true) & dp_search(Y_inst, y_target, false);


	if (result) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	return 0;

}
