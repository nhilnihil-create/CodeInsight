#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n,q;
    string s;
    cin>>n>>q>>s;
    vector<int> dat(n+10),ans(q);//0-indexed [l,r]
    for(int i=1;i<n;i++){
        if(s[i-1]=='A'&&s[i]=='C'){
            dat[i]++;
        }
        dat[i]+=dat[i-1];
    }
    rep(i,q){
        int l,r;
        cin>>l>>r;
        l--;r--;
        ans[i]=dat[r]-dat[l];
    }
    rep(i,q){
        cout<<ans[i]<<endl;
    }
    return 0;
}