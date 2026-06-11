#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,q;
    string s;
    cin>>n>>q>>s;
    vector<int>ans(n,0);
    rep(i,n-1){
        ans[i+1]=ans[i];
        if(s[i]=='A'&&s[i+1]=='C')ans[i+1]++;
    }
    rep(i,q){
        int l,r;
        cin>>l>>r;
        l--; r--;
        printf("%d\n",ans[r]-ans[l]);
    }
    return 0;
}