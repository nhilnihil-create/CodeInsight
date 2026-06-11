#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 2000000000
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    
    ll n,M;
    cin >>n>>M;
    vector<vector<ll>>  s(M);
    rep(i,M){
        ll k;
        cin >> k;
        rep(j,k){
            ll tmp;
            cin >> tmp;
            s[i].pb(tmp-1);
        }
    }
    vector<ll> p(M); 
    rep(i,M){
        cin >> p[i];
    }
    vector<vector<bool>> S(1<<n);
    rep(bit,1<<n){
        
        rep(i,n){
            if(bit&(1<<i)){
                S[bit].pb(1);
            }else{
                S[bit].pb(0);
            }
        }
    }

    vector<bool> L(n);

    ll cnt =0;
    rep(i,1<<n){
        rep(j,M){
            bool pt = 0;
            rep(k,s[j].size()){
                if(S[i][s[j][k]] == 1){
                    pt ^= 1;
                }
            }
            if(pt !=p[j])  break;
            if(j == M-1){
                cnt++;
            }
        }
    }


    cout << cnt << endl;

    return 0;
    

}