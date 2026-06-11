#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<int>;
using P = pair<int,int>;

int main()
{
    int n;cin >>n;
    V c(n),s(n),f(n);
    rep(i,n-1)cin >>c[i]>>s[i]>>f[i];
    rep(i,n){
        ll now=0;
        for(int j=i;j<n-1;j++){
            if(now<s[j])now=s[j];
            else if(now%f[j]!=0)now+=(f[j]-now%f[j]);
            now+=c[j];
        }
        cout <<now << endl;
    }
    return 0;
}
