#include <iostream>
#include <string>
#include <sstream>  // istringstream
#include <vector>

using namespace std;

int main()
{
	int N = 0;
	std::string lineBuf;

	cin >> N;

	std::vector<int> vctA(N + 2);
#if 0
	cin >> lineBuf;
	istringstream iss(lineBuf);
	string s;
	while (iss >> s){
		cout << s;
	}
#else
	//istringstream iss(lineBuf);
	//string s;
	vctA[0] = 0;
	for (int i = 0; i < N; ++i){
		// int num = 0;
		cin >> vctA[i + 1];
	}
	vctA[N + 1] = 0;
	// std::vector<int> vctA2()
#endif

#if 1
	// 最初に全部回った金額を算出
	int sum = 0;
	int CorPrep = 0;// 1つ前の座標
	for (int i = 0; i < N; ++i){
		int curCor = vctA[i + 1];
		int money = std::abs(curCor - CorPrep);
		sum += money;
		CorPrep = curCor;
	}
	int lastMoney = std::abs(CorPrep); // - 0
	sum += lastMoney;
	// cout << sum << std::endl;

	CorPrep = 0;
	// int CorNext = vctA[2];
	int CorNext = 0;
	int CorCur = vctA[1];
	for (int i = 0; i < N; ++i){
		int CorNext = vctA[i + 2];
#if 0
		if (CorPrep <= CorCur && CorCur <= CorNext){
			cout << sum << std::endl;
		}
		else
#endif		
		if ((CorCur < CorPrep && CorCur < CorNext)
			|| (CorCur > CorPrep && CorCur > CorNext))
		{
			int money1 = std::abs(CorCur - CorPrep);
			int money2 = std::abs(CorCur - CorNext);

			
			if (money1 < money2){
				cout << sum - money1 * 2 << std::endl;
			}
			else {
				cout << sum - money2 * 2 << std::endl;
			}
		}
		else {
			cout << sum << std::endl;
		}
		CorPrep = CorCur;
		CorCur = CorNext;
	}

#else
	for (int j = 0; j < N; ++j){
		int sum = 0;
		int CorPrep = 0;// 1つ前の座標
		for (int i = 0; i < N; ++i){
			if (i == j){
				continue;
			}
			int money = std::abs(vctA[i] - CorPrep);
			sum += money;
			CorPrep = vctA[i];
		}
		int lastMoney = std::abs(CorPrep); // - 0
		sum += lastMoney;
		cout << sum << std::endl;
	}
#endif

	return 0;
}