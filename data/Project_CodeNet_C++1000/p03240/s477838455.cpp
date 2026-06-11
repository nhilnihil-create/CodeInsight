#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    int n;
    cin>>n;
    vector<tuple<int,int,ll>> data;
    rep(i,0,n){
        int a,b; ll c;
        cin>>a>>b>>c;
        data.emplace_back(a,b,c);
    }
    ll xans=0;
    ll yans=0;
    ll hans=0;
    rep(i,0,101){
        rep(j,0,101){
            ll temp_h=0;
            rep(k,0,n){
                if(get<2>(data[k])!=0){
                    temp_h = get<2>(data[k]) + abs(i-get<0>(data[k])) + abs(j-get<1>(data[k]));
                    break;
                }
            }
            bool can=true;
            rep(k,0,n){
                if(max(temp_h - abs(get<0>(data[k])-i) - abs(get<1>(data[k])-j),0LL)!=get<2>(data[k])){
                    can=false;
                    break;
                }
            }
            if(can==true){
                xans=i; yans=j; hans=temp_h;
                goto END;
            }
        }
    }
    END:
    cout<<xans<<" "<<yans<<" "<<hans<<endl;
}