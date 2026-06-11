#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
using ipair = pair<int,int>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
const int MOD=1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){ 
    int n;cin>>n;
    ll ans = 0;
    rep(i,n){
        ll a;
        cin >> a;
        while(a%2==0){
            a/=2;
            ans++;
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}