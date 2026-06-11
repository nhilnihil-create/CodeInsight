#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a[3];
    rep(i,3){
        cin>>a[i];
    }
    sort(a,a+3);
    cout<<a[2]-a[0]<<endl;

    return 0;
}
