#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    char s;
    int cnt=0;
    rep(i,3){
        cin>>s;
        if(s=='1')cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}
