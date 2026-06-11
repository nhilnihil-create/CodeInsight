#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;



int main() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.length();
	string max_s;
	for (int i = 0; i < n; i++) {
		max_s += 'z';
	}
	vector<string> dic(k, max_s);

	for (int i = 0; i < n ; i++) {
		for (int j = 1; j + i <= n && j <= k; j++) {

			string sb = s.substr(i, j);

			//cout << sb << endl;
			for (int l = 0; l < k; l++) {

				if (dic[l] > sb) {

					string tmp = dic[l];
					dic[l] = sb;
					sb = tmp;
				}
				else if (dic[l] == sb) {
					break;
				}

			}
		}
	}

	cout << dic[k - 1] << endl;


}