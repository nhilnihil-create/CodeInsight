#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)

using namespace std;
void solve(){
    int a[3];
    rep(i,0,3){
        cin>>a[i];
    }
    sort(a,a+3);
    int res=a[2]*10+a[1];
    cout<<a[0]+res<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
