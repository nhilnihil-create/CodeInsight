#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long dp[200001];

#define ll long long


struct Tree {
    typedef ll T;
    const T LOW =-1e9;
    T f(T a, T b) { return max(a,b); }// this is the function change it to sum,min,max
    ll n;
    vector<T> s;
    Tree() {}
    Tree(ll m, T def=-1e9) { init(m, def); }//the value of def should be like 1e9 for min and -1e9 for max and 0 for sum
    void init(ll m, T def) {
        n = 1; while (n < m) n *= 2;
        s.assign(n + m, def);
        s.resize(2 * n, LOW);
        for (ll i = n; i --> 1; )
            s[i] = f(s[i * 2], s[i*2 + 1]);
    }
    void update(ll pos, T val) {
        pos += n;
        s[pos] = val;
        for (pos /= 2; pos >= 1; pos /= 2)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(ll l, ll r) { return que(1, l, r, 0,n); }
    T que(ll pos, ll l, ll r, ll lo, ll hi) {
        if (r <= lo || hi <= l) return LOW;
        if (l <= lo && hi <= r) return s[pos];
        ll m = (lo + hi) / 2;
        return f(que(2 * pos, l, r, lo, m),que(2 * pos + 1, l, r, m, hi));
    }
};


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    memset(dp, 1, sizeof(dp));
    
    int n;
    cin>>n;
    int h[n];
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>h[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
  //  int prev[n] = {-1};
    Tree s(200000);
    //cout<<endl;
    long long ans = 0;
    
    //cout<<endl;
    for(int i = 0 ; i < n ; i++){
        ll m = s.query(0,h[i]);

        //cout<<"here"<<endl;
        if(m == -1e9){
            dp[i] = a[i];
            s.update(h[i], dp[i]);
        }
        else{
            dp[i] = a[i] + m;
            s.update(h[i], dp[i]);
        }
       // cout<<dp[i]<<" ";
        if(ans < dp[i]){
                ans = dp[i];
        }
    }
   // cout<<endl;
    cout<<ans<<endl;

    return 0;
}
