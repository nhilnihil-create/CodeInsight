#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9+5)
#define INFLL ((LL)4e18)
#define ALL(x) (x).begin(),(x).end()
#define BIT(x) (1LL << (x))
using namespace std;

int main(){
	string str;
	cin >> str;
	int ans = str.size();
	REP(i, str.size()/2){
		if(str[i]!=str[i+1]){
			ans = min(ans, (int)str.size()-i-1);
		}
	}
	for(int i=str.size()-1;i>str.size()/2;--i){
		if(str[i-1]!=str[i]){
			ans = min(ans, i);
		}
	}
	cout << ans << endl;
	return 0;
}
