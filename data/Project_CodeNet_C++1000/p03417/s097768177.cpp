#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main() {
    ll N,M; cin>>N>>M;
    if(N>=2 && M>=2)cout<<(N-2)*(M-2)<<endl;
    else if(N==1&&M==1)cout<<1<<endl;
    else{
        ll a =max(N,M);
        cout<<a-2<<endl;
    }
}
