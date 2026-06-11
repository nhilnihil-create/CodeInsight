#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int r;
    cin>>r;
    if(r<1200)cout<<"ABC"<<endl;
    else if(r<2800)cout<<"ARC"<<endl;
    else cout<<"AGC"<<endl;

    return 0;
}
