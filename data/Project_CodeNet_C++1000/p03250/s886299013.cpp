#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    vector<int> a(3);
    rep(i,3) cin>>a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    string A,B,C;
    A=to_string(a[0]);
    B=to_string(a[1]);
    C=A+B;
    int ans=stoi(C)+a[2];
    cout<<ans<<endl;
}   
