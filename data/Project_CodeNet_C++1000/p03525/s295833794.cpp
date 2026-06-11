#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
//typedef vector<vector<P> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//入力
ll n;
vector<ll>d;

//途中で使う
vector<bool>kakutei;
vector<int>num;
vector<int>v;


int main(){
    cin >> n;
    d.resize(n);
    rep(i,n)cin>>d[i];
    num.resize(15,0);
    kakutei.resize(50,false);
    kakutei[0]=true;
    kakutei[24]=true;
    kakutei[48]=true;
    ll c = 0;
    rep(i,n){
        num[d[i]]++;
    }
    if(num[0]>0){
        cout << 0 << endl;
        return 0;
    }
    rep(i,15){
        if(num[i]>=3){
            cout << 0 << endl;
            return 0;
        }
        if(num[i]==2){
            kakutei[i]=true;
            kakutei[24-i]=true;
            kakutei[i+24]=true;
            kakutei[48-i]=true;
            continue;
        }
        if(num[i]==0)continue;
        v.push_back(i);
    }
    int l = v.size();
    for(int bit=0;bit<(1<<l);bit++){
        vector<bool>kari(50,false);
        rep(i,l){
            if((bit>>i)&1){
                kari[v[i]]=true;
                kari[v[i]+24]=true;
            }
            else{
                kari[24-v[i]]=true;
                kari[48-v[i]]=true;
            }
        }
        int last = 0;
        ll now = INF;
        rep(i,50){
            if(i==0)continue;
            if(kakutei[i]||kari[i]){
                chmin(now,i-last);
                last=i;
            }

        }
        chmax(c,now);
    }

    cout << c << endl;
    return 0;
}