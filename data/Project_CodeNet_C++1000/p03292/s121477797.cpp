#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    vector<int> v(3);
    rep(i,3) cin>>v[i];

    sort(v.begin(),v.end());
    
    int ans = 0;
    rep2(i,1,3){
        ans += v[i]-v[i-1];
    }
    
    cout<<ans<<endl;

    return 0;
}
