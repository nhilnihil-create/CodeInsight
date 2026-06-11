#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(abs(c-a)<=d||(abs(c-b)<d&&abs(b-a)<=d))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}