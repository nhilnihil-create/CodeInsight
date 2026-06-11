#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;cin>>n;
    vector<int> a;
    a.push_back(0);
    rep(i,n){
        int t;cin>>t;
        a.emplace_back(t);
    }
    a.push_back(0);
    ll sum = 0;
    for(int i=0; i<n+1; i++){
        sum += abs(a[i+1]-a[i]);
    }
    for(int i=1; i<=n; i++){
        ll ans;
        if(a[i-1] < a[i+1]){
            if(a[i]<a[i-1]){
                ans = sum - abs(a[i-1]-a[i]) * 2;
            }else if(a[i-1]<=a[i] && a[i]<=a[i+1]){
                ans = sum;
            }else{
                ans = sum - abs(a[i+1]-a[i])*2;
            }
        }else if(a[i-1]>a[i+1]){
            if(a[i] < a[i+1]){
                ans = sum-abs(a[i+1]-a[i])*2;
            } else if(a[i+1]<=a[i] && a[i]<a[i-1]){
                ans = sum;
            } else{
                ans = sum-abs(a[i-1]-a[i])*2;
            }
        } else{
            ans = sum - abs(a[i+1]-a[i])*2;
        }
        cout<<ans<<endl;
    }
}
// arc093_a