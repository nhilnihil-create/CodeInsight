#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int A, B, C, X;
	cin >> A >> B >> C >> X;
	int num = 0;
	REP(i, A + 1){
		REP(j, B + 1){
			REP(k, C + 1){
				if(500 * i + 100 * j + 50 * k == X)
					num++;
			}
		}
	}
	cout << num << endl;
}
