#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>

#define repAll(n) (n).begin(), (n).end()
#define repConAll(n) (n).cbegin(), (n).cend()

using namespace std;


namespace {

}


int main()
{
	int N;
	//vector<string> S;
	set<string> setS;
	set<char> h1{ 'M', 'A', 'R', 'C', 'H' };
	map<char, long long> countS;

	cin >> N;

	countS['M'] = 0;
	countS['A'] = 0;
	countS['R'] = 0;
	countS['C'] = 0;
	countS['H'] = 0;
	vector<char> vctHeader{ 'M', 'A', 'R', 'C', 'H' };

	for (int i = 0; i < N; ++i){
		string s;
		cin >> s;
		for (auto elem : vctHeader){
			if (s[0] == elem){
				++countS[elem];
			}
		}
	}

	long long allCount = 0;
	for (int i = 0; i < 5; ++i){
		for (int j = i + 1; j < 5; ++j){
			for (int k = j + 1; k < 5; ++k){
				if (i != j && j != k && i != k){
					allCount += countS[vctHeader[i]] * countS[vctHeader[j]] * countS[vctHeader[k]];
				}
			}
		}
	}

	cout << allCount << endl;

	return 0;
}