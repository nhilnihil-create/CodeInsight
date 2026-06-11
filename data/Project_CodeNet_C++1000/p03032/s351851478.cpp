#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N,K;
    cin>>N>>K;
    vector<ll> V(N);
    vector<P> gomi(N);
    rep(i,N){
        cin>>V.at(i);
        gomi.at(i).first=V.at(i);
        gomi.at(i).second=i;
    }
    sort(gomi.begin(),gomi.end());//捨てるべきやつ
    vector<ll> lsum(N+1),rsum(N+1);//左右からi個の和
    rep(i,N){
        lsum.at(i+1)=lsum.at(i)+V.at(i);
        rsum.at(i+1)=rsum.at(i)+V.at(N-i-1);
    }
    ll ans=0;
    rep(cat,K+1){//cat個とってK-cat個捨てる
        ll now=0;
        int rel=K-cat;
        if(cat>=N){
            now=lsum.at(N);
            rep(i,min(rel,N)){
                if(gomi.at(i).first<0){now-=gomi.at(i).first;}
            }
            chmax(ans,now);
        }
        else{
            ll nownow=0;
            rep(left,cat+1){//左からleft個、右からcat-left個
                nownow=lsum.at(left)+rsum.at(cat-left);
                int count=0;
                rep(i,N){
                    if(gomi.at(i).second<left || gomi.at(i).second>N-1-cat+left){
                        if(count<rel && gomi.at(i).first<0){
                            nownow-=gomi.at(i).first;
                            count++;
                        }
                    }
                }
                //chmax(now,nownow);
                chmax(ans,nownow);
            }
            //chmax(ans,now);
        }
    }
    cout<<ans<<endl;
}