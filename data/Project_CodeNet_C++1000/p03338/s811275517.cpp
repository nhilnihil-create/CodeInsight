#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mmax=1000009;

int main(void){
    int n;
    string s;
    cin>>n>>s;
    vector<int> left(26),right(26);
    rep(i,n) left[s[i]-'a']++;
    int ans=0;
    rep(i,n){
        left[s[i]-'a']--;
        right[s[i]-'a']++;
        int temp=0;
        rep(j,26) if(left[j]>0 && right[j]>0) temp++;
        chmax(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}
