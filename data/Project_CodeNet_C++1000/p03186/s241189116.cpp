#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll a,b,c;cin>>a>>b>>c;
    cout<< b + min(c, a+b+1);
}