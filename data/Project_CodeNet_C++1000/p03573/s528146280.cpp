#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,c;
    cin>>a>>b>>c;
    if(a!=b&&b!=c)cout<<b<<endl;
    if(a!=b&&a!=c)cout<<a<<endl;
    if(a!=c&&b!=c)cout<<c<<endl;

    return 0;
}
