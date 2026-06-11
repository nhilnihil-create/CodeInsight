#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	int N;
	cin >> N;
	vector<string> S(N);
	rep(i,N){
		cin >> S[i];
	}

	ll ans = 0;
	rep(i,N){
		// A = 0, B = i の時に線対称かをチェックする
		bool check = true;
		rep(j,N){
			rep(k,N){
				// (j,k) -> (j,(k+i)%N)
				// (?,?) -> ((k+i)%N, j)
				// (?,?) == ((k+i)%N, (j+N-i)%N);
				if(S[j][k] == S[(k+i)%N][(j+N-i)%N]){
					// ok
				} else {
					check = false;
					break;
				}
			}
			if(check == false){
				break;
			}
		}
		if(check) ans ++;
	}
	cout << ans * N << endl;
}
