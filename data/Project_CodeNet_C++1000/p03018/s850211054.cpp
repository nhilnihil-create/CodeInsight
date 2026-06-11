#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;
static long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s; cin >> s;
	int N = s.size();
	LL ans= 0;
	LL ca = 0;
	for(int i=0; i<N; i++){
		if(s[i] == 'A'){
			ca++;
		}
		else if(s[i] == 'C'){
			ca = 0;
		}
		else if(s[i] == 'B'){
			if(i+1<N && s[i+1] == 'C'){
				ans += ca;
				i++;
			}
			else if(i+1<N && s[i+1] == 'B'){
				ca = 0;
				i++;
			}
			else if(i+1<N && s[i+1] == 'A'){
				ca = 1;
				i++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}