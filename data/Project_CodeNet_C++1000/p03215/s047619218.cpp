#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N,K; cin >> N >> K;
    ll a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    ll sum[N+1]={};
    vector<ll> su;
    for(int i=0;i<N;i++){
        sum[i+1]=sum[i]+a[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            su.push_back(sum[j]-sum[i-1]);
        }
    }
    for(int i=45;i>=0;i--){
        vector<ll> tmp;
        for(int j=0;j<su.size();j++){
            if(su[j]&(1LL<<i)) tmp.push_back(su[j]);
        }
        if(tmp.size()>=K){
            su=tmp;
        }
    }
    ll ans=su[0];
    for(int i=1;i<K;i++){
        ans=ans&su[i];
    }
    cout << ans << endl;
}