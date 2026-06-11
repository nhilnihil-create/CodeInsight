#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;


int main() {
    ll N,M;
    cin>>N>>M;
    int mx =max(N,M);
    int mn =min(N,M);
    if(mn==1){
        if(mx==1)cout<<1<<endl;
        else cout<<mx-2<<endl;
    }
    else cout <<(ll)(N-2)*(M-2)<<endl;
}