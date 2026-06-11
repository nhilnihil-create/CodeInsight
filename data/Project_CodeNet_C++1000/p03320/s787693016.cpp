#include <iostream>
#include <cstdint>
#include <utility>
#include <vector>
#include <cassert>

const uint32_t MAX_P = 19;

uint64_t pow10[MAX_P];

void calc_pow() {
	pow10[0] = 1;
	for (uint32_t i = 1;i < MAX_P;i++) {
		pow10[i] = pow10[i - 1] * 10;
	}
}

void generate_snoke(uint64_t num, uint64_t digSum, uint32_t digI, std::vector<uint64_t> &ans, uint32_t minDig = 0) {
	uint32_t dig = num / pow10[digI] % 10;

	//std::cerr << "num: " << num << " digS: " << digSum << " i: " << digI << std::endl;

	uint32_t curD = dig;
	uint64_t curNum = num;
	uint64_t curSum = digSum;

	while (curD > minDig) {
		if (curSum * pow10[digI] >= curNum) { 
			curNum = curNum - pow10[digI];
			curSum--;
			curD--;
		} else {
			break;
		}
	}
	for (uint32_t i = curD;i <= dig;i++) {
		if (digI > 0) {
			generate_snoke(curNum, curSum, digI - 1, ans);
		} else {
			ans.push_back(curNum);
		}
		curNum += pow10[digI];
		curSum++;
	}

}

std::vector<uint64_t> generate_snoke() {
	std::vector<uint64_t> ans;
	uint64_t curNines = 9;
	for (uint32_t i = 1;i < 16;i++) {
		generate_snoke(curNines, 9 * i, i - 1, ans, 1);
		curNines = curNines * 10 + 9;
	}
	return ans;

}

int main() {
	calc_pow();
	std::vector<uint64_t> snokes = generate_snoke();
	uint32_t k;
	std::cin >> k;
	for (uint32_t i = 0;i < k;i++) {
		std::cout << snokes[i] << "\n";
	}
	//std::cerr << snokes.size() << "\n";
	//std::cerr << snokes.back() << "\n";


}


