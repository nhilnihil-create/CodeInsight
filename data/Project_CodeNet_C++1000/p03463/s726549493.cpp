#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,a,b;cin>>n>>a>>b;
    cout<< ( (b-a)%2?"Borys":"Alice" );
}