#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll N,K; cin>>N>>K;
    ll ans =0;
    ans+=(N/K)*(N/K)*(N/K);
    if(K%2!=0){
        cout<<ans<<endl;
        return 0;
    }
    ll k=N/(K/2)-N/K;
    ans+=k*k*k;
    cout<<ans<<endl;
    
}


