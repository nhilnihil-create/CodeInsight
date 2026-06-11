#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll a,b;cin>>a>>b;
    if(b%a)cout<<b-a;
    else cout<<b+a;
}

