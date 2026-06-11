#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    if(n/1000==n/100%10&&n/1000==n/10%10||n/100%10==n%10&&n%10==n/10%10)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
