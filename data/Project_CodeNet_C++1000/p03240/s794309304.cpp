#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 100000000;
ll i,j,k;
ll mod=1000000007;

int main(){
    ll n;cin>>n;
    map<pair<ll,ll>,ll> H;
    vector<pair<ll,ll>> P(n);
    for(i=0;i<n;i++){
        ll x,y,h;
        cin>>x>>y>>h;
        P[i]=make_pair(x,y);
        H[make_pair(x,y)]=h;//座標と高さの情報
    }

    ll h;
    for(i=0;i<=100;i++){
        for(j=0;j<=100;j++){
            for(k=0;k<n;k++){
                if(H[P[k]]!=0){
                    //高さが0のものは情報として弱い
                    //(例えば、高さが0のときは、xが1centerから離れても、高さは0のままであるので、centerを特定する情報としては弱い)
                    h=H[P[k]]+abs(P[k].first-i)+abs(P[k].second-j);//centerを(i,j)と仮定したときのpyramidの高さ(一意に定まるので、H!=0ならどこを選んでもよい)
                    break;
                }
            }
            
            bool ok=true;
            for(k=0;k<n;k++){
                if(max(h-abs(P[k].first-i)-abs(P[k].second-j),(ll)0)!=H[P[k]]){//他の情報に一致するのか
                    ok=false;
                }
            }
            if(ok){cout<<i<<" "<<j<<" "<<h<<endl;return 0;}//他の情報全てと一致したら答え
        }
    }

    return 0;
}