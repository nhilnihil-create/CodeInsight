#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll x,y;cin>>x>>y;
    cout<<( (x%y)?x:-1 );
}