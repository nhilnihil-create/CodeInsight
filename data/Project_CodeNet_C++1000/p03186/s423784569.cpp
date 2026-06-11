#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod =1000000007;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    if(b>=c-1){cout<<b+c;return 0;}
    else{cout<<2*b+1+min(c-b-1,a);}
}