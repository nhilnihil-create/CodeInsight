#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll BIG=1e9;

int mp[160][160];
int sum[160][160];

int main(){
    int N,K; cin>>N>>K;
    vector<ll> x,y;
    vector<pair<ll,ll>> d;
    for(int i=0;i<N;i++){
        ll a,b; cin>>a>>b;
        d.push_back(make_pair(a,b));
        x.push_back(a-1);
        x.push_back(a);
        x.push_back(a+1);
        y.push_back(b-1);
        y.push_back(b);
        y.push_back(b+1);
    }

    
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(d.begin(),d.end());

    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    for(int i=0;i<N;i++){
        ll X=d.at(i).first, Y=d.at(i).second;
        mp[find(x.begin(),x.end(),X)-x.begin()][find(y.begin(),y.end(),Y)-y.begin()]++;
    }

    for(int i=0;i<x.size();i++){
        for(int j=0;j<y.size();j++) sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+mp[i][j];
    }

    int X=x.size(), Y=y.size();
    ll ans=(x.at(X-1)-x.at(0))*(y.at(Y-1)-y.at(0));

    for(int i=0;i<X;i++){
        for(int j=i;j<X;j++){
            for(int p=0;p<Y;p++){
                for(int q=p;q<Y;q++){
                    while(sum[j+1][q+1]-sum[i][q+1]-sum[j+1][p]+sum[i][p]<K){
                        q++;
                        if(q==Y) break;
                        if((x.at(j)-x.at(i))*(y.at(q)-y.at(p))>=ans) break;
                    }

                    if(q==Y) break;
                    ans=min(ans,(x.at(j)-x.at(i))*(y.at(q)-y.at(p)));
                }
            }
        }
    }
    
    cout<<ans<<endl;
    



}