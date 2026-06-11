#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> D(N);
    rep(i,N) cin >> D[i];
    int M;
    cin >> M;
    vector<int> T(M);
    rep(i,M) cin >> T[i];
    sort(D.begin(),D.end());
    sort(T.begin(),T.end());
    int ix=0;
    for(int i=0;i<M;i++){
        while(ix<N){
            if(D[ix]==T[i]){
                ix++;
                break;
            }
            ix++;
            if(ix==N){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}