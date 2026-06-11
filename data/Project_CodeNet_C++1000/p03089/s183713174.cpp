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
    vector<ll> b(N),v;
    rep(i,N) cin >> b[i];
    rep(i,N){
        rep(j,b.size()){
            if(b[int(b.size())-1-j] == int(b.size())-j){
                b.erase(b.begin() + int(b.size())-1-j);
                //cout << "a:"<<b.size() << " "<<j<<endl;
                v.push_back(int(b.size())+1-j);
                break;
            }
        }
    }
    if(b.size() != 0){
        cout << -1 << endl;
        return 0;
    }
    rep(i,N){
        cout << v[N-1-i] << endl;
    }
}
