#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m,d;cin>>n>>m>>d;
    if(d==0)cout<<fixed<<setprecision(18)<<(m-1.0)/(n*1.0);
    else cout<<fixed<<setprecision(18)<<(2.0*(n-d)*(m-1))/(n*n*1.0);
}