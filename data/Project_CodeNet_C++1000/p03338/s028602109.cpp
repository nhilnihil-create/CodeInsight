#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
	int ans = 0;
	int N;
	string S;
	cin >> N >> S;
	for(int i=1; i<N; ++i){
		string T = "";
		int count = 0;
		for(int j=0; j<i; ++j){
			bool flag = false;
			for(int l=0; l<T.length(); ++l){
				if(S[j]==T[l]){
					flag = true;
					break;
				}
			}
			if(flag) continue;
			for(int k=i; k<N; ++k){
				if(S[j]==S[k]){
					T.push_back(S[j]);
					++count;
					break;
				}
			}
		}
		ans = max(ans, count);
	}
	cout << ans << endl;
}