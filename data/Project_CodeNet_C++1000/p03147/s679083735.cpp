#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    int n; cin >> n;
    vector<int> h(n+2,-1);
    rep(i,n) cin >> h[i+1];
    
    int ans=0;
    int lm=0;
    rep2(i,n+1){
        if(h[i]>=h[i-1] && h[i]>h[i+1]){
            ans+=h[i]-lm;
        }
        else if(h[i]<h[i-1] && h[i]<=h[i+1]){
            lm=h[i];
        }
    }
    cout << ans << endl;
}