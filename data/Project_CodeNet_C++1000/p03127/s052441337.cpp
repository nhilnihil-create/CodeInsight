#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;


int gcd(int a, int b){
    if(a%b == 0){
        return(b);
    }else{
        return(gcd(b, a%b));
    }
}

int lcm(int a, int b){
   return a * b / gcd(a, b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int ans=a[0];
    rep(i,n){
        ans=gcd(ans,a[i]);
    }
    cout << ans << "\n";
    return 0;
}   