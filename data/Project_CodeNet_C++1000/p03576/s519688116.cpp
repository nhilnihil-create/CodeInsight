#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 1100000000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> P;

vector<ll> X,Y;

int main(){
    ll x[100],y[100],ans=7000000000000000000;
    int N,K,count=0;
    cin>>N>>K;

    for(int i=0;i<N;i++){
        cin>>x[i]>>y[i];
        X.push_back(x[i]);
        Y.push_back(y[i]);
    }

    sort(X.begin(),X.end());sort(Y.begin(),Y.end());
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            for(int k=0;k<N-1;k++){
                for(int l=k+1;l<N;l++,count=0){
                    for(int n=0;n<N;n++){
                        if(x[n]>=X[i] && x[n]<=X[j] && y[n]>=Y[k] && y[n]<=Y[l]) count++;
                    }
                    //cout<<count<<endl;
                    if(count>=K) ans=min(ans,(X[j]-X[i])*(Y[l]-Y[k]));
                }
            }
        }
    }
    cout<<ans<<endl;


}
