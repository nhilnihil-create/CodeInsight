#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll a,b;cin>>a>>b;
    if(a+b==15)cout<<"+";
    else if(a*b==15)cout<<"*";
    else cout<<"x";
}