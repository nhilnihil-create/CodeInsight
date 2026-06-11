#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 999999999;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    llint N, A, B;
    cin >> N >> A >> B;
    if(N+1 < A+B) puts("-1");
    else if(A*B < N) puts("-1");
    else{
        vector<llint> P;
        llint now=A*B, ct=N-(A+B-1);
        REP(b, B){
            for(int a=A-1; a>=0; a--){
                if(a == A-1 || b == 0) P.pb(now-a);
                else if(ct > 0){
                    P.pb(now-a);
                    ct--;
                }else{
                    break;
                }
            }
            now -= A;
        }
        vector<llint> Pst = P;
        sort(All(Pst));

        REP(i, N){
            cout << (lower_bound(All(Pst), P[i])-Pst.begin())+1 << (i == N-1 ? "\n" : " ");
        }
    }
    
    return 0;
}