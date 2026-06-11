#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define fi first
#define se second
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int N;cin >> N;
    if(N == 1){
        cout << 1 << endl;
        return 0;
    }
    string S[2*N];
    REP(i,N){cin >> S[i];S[i] += S[i];}
    REPP(i,N,2*N){S[i] = S[i-N];}

    int ans = 0;
    bool flag = 1;
	int K = N;
    REP(j,N){//左上の点を決定
        int i = 0;
        int x = i,y = j,A = 0;
        while(flag){
            REPP(k,x+1+A,x+N){
                if(S[k][y] != S[y-j+i][k+j-i]){
                    flag = 0;K--;
                    break;
                }
                else if(k == x+N-1 && A == N-2){
                    ans += K;K--;
                    flag = 0;
                }
            }
            y++;A++;
        }
        flag = 1;
    }
  K = N-1;

    REPP(i,1,N){//左上の点を決定
        int j = 0;
        int x = i,y = j,A = 0;
        while(flag){
            REPP(k,x+1+A,x+N){
                if(S[k][y] != S[y-j+i][k+j-i]){
                    flag = 0;K--;
                    break;
                }
                else if(k == x+N-1 && A == N-2){
                    ans += K;K--;
                    flag = 0;
                }
            }
            y++;A++;
        }
        flag = 1;
    }
    cout << ans << endl;
}
