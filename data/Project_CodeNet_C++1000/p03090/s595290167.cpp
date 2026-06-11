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
    ll S = (N*(N+1))/2;
    ll ngroup = 0;
    deque<ll> v;
    rep(i,N){
        v.push_back(i+1);
    }
    if(N % 2){
        ngroup = (N+1)/2;
    }else{
        ngroup = N/2;
    }
    vector<vector<ll>> u(ngroup);
    ll ss = S/ngroup;
    rep(i,ngroup){
        ll a = v.back();
        v.pop_back();
        u[i].push_back(a);
        if(a == ss){
            continue;
        }else{
            a = v.front();
            v.pop_front();
            u[i].push_back(a);
        }
    }
    ll cnt = 0;
    rep(i,ngroup){
        rep(j,u[i].size()){
            rep(k,i){
                rep(l,u[k].size()){
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    //cout << "ngroup:"<<ngroup<<endl; 
    rep(i,ngroup){
        rep(j,u[i].size()){
            rep(k,i){
                rep(l,u[k].size()){
                    cout << u[i][j] << " " << u[k][l] << endl;
                }
            }
        }
    }


    /*
    cout << (N-1)*(N-1) - N + 1 << endl;
    vector<Pll> v;
    for(int i=1;i<N;i++){
        for(int j=1;j<=N;j++){
            if(N-j != i && j != i){
                cout << i << " " << j << endl;
            }
        }
    }*/
    /*
    v.push_back(Pll(N, 1));
    v.push_back(Pll(N, N-1));
    rep(i, N-3){
        rep(j, i){
            v.push_back(Pll(i+2,j+2));
        }
        v.push_back(Pll(i+2,1));
        v.push_back(Pll(i+2,N-1));
        v.push_back(Pll(i+2,N));
    }
    cout << v.size() << endl;
    rep(i,v.size()){
        cout << v[i].first << " " << v[i].second << endl;
    }*/
}
