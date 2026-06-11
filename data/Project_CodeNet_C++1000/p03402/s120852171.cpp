#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
	int a,b;
	cin >> a >> b;
	char ans[100][100];
	REP(i,50)
		REP(j,100)
			ans[i][j] = '#';
	for(int i = 50; i < 100; i++)
		REP(j,100)
			ans[i][j] = '.';
	int cnt = 1;
	for(int i = 0; i < 50; i += 2){
		for(int j = 0; j < 100; j += 2){
			if(cnt < a){
				ans[i][j] = '.';
				cnt++;
			}else{
				break;
			}
		}
	}
	cnt = 1;
	for(int i = 51; i < 100; i += 2){
		for(int j = 0; j < 100; j += 2){
			if(cnt < b){
				ans[i][j] = '#';
				cnt++;
			}else{
				break;
			}
		}
	}
	cout << 100 << " " << 100 << endl;
	REP(i,100){
		REP(j,100){
			cout << ans[i][j];
		}
		cout << endl;
	}
}