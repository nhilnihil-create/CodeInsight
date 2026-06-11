#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    vector<int>A(3);
    int ans=0;
    rep(i,3){
        cin>>A.at(i);
    }
    sort(A.begin(),A.end());
    ans+=abs(A.at(1)-A.at(0));
    ans+=abs(A.at(2)-A.at(1));
    cout<<ans<<endl;
}