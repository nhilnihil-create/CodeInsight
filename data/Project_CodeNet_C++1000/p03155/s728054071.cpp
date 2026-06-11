#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,h,w;cin>>n>>h>>w;
    cout<<(n-h+1)*(n-w+1);
}