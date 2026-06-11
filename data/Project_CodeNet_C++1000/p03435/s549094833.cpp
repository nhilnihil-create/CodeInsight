#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	vector<vector<int>> c(3, vector<int>(3));
	int sum = 0;
	REP(i, 3){
		REP(j, 3){
			cin >> c[i][j];
			sum += c[i][j];
		}
	}
	vector<int> a(3);
	vector<int> b_1(3);
	vector<int> b_2(3);
	vector<int> b_3(3);

	if(sum % 3 != 0){
		cout << "No" << endl;
		return 0;
	}else{
		REP(a1, 101){
			REP(a2, 101){
				REP(a3, 101){
					a[0] = a1;
					a[1] = a2;
					a[2] = a3;
					b_1[0] = c[0][0] - a1;
					b_1[1] = c[0][1] - a1;
					b_1[2] = c[0][2] - a1;
					b_2[0] = c[1][0] - a2;
					b_2[1] = c[1][1] - a2;
					b_2[2] = c[1][2] - a2;
					b_3[0] = c[2][0] - a3;
					b_3[1] = c[2][1] - a3;
					b_3[2] = c[2][2] - a3;

					if(b_1[0] == b_2[0] && b_1[1] == b_2[1] && b_1[2] == b_2[2] && b_3[0] == b_2[0] && b_3[1] == b_2[1] && b_3[2] == b_2[2]){
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "No" << endl;

}
