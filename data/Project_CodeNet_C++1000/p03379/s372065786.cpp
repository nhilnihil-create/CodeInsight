#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()


int main(){
    int N;cin>>N;
    vector<int>X(N);
    vector<int>Y(N);

    rep(i,N){
        cin>>X.at(i);
        Y.at(i)=X.at(i);
    }
    sort(all(Y));
    int ans1=Y.at(N/2);
    int ans2=Y.at(N/2-1);
    rep(i,N){
        if(X.at(i)<=ans2){
            cout<<ans1<<endl;
        }else{
            cout<<ans2<<endl;
        }
    }
    
}
