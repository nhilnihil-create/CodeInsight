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
    if(a*b>a*c&&b*c>a*c)cout<<a*c/2<<endl;
    else if(a*c>a*b&&b*c>a*b)cout<<a*b/2<<endl;
    else if(a*b>b*c&&a*c>b*c)cout<<b+c/2<<endl;

    return 0;
}
