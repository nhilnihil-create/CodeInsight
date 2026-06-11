#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    ll n,m;
    cin>>n>>m;
    if(n==1&&m==1)cout<<1<<endl;
    else if(n==1)cout<<m-2<<endl;
    else if(m==1)cout<<n-2<<endl;
    else cout<<(n-2)*(m-2)<<endl;
}