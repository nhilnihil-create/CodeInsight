#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x,y;
    cin>>x>>y;
    int cnt=0;
    while(1){
        x=x*2;
        cnt++;
        if(x>y)break;
    }
    cout<<cnt<<endl;


    return 0;
}
