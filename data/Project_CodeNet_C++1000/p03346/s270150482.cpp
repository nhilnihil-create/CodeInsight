#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N;
    cin >> N;
    vector<ll> P(N),Q(N);
    rep(i,N){
        cin >> P[i];
        Q[P[i]-1] = i;
    }
    ll cnt = -1;
    ll prev = -1;
    ll M = 1;
    rep(i,N){
        //cout << Q[i] << " ";
        if(prev < Q[i]){
            cnt++;
        }else{
            cmax(M,cnt+1);
            cnt = 0;
        }
        prev = Q[i];
    }
    //cout << endl;
    cmax(M,cnt+1);
    cout << N-M << endl;    
}
