#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a=min(a,b);
    c=min(c,d);
    cout<<c+a<<endl;
}