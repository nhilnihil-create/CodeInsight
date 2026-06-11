#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){

    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;

    vector<int> sum(n+1, 0);
    rep(i,n){
        if(i+1<n && s[i]=='A' && s[i+1]=='C') sum[i+1]=sum[i]+1;
        else sum[i+1]=sum[i];
    }

    rep(i,q){
        int l, r;
        cin>>l>>r;
        l--;r--;
        cout<<sum[r]-sum[l]<<endl;
    }
   
    return 0;
}
