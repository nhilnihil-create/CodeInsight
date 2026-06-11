#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,d,x;
    cin>>n>>d>>x;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    for (int i=1; i<=d; i++) {
        for (int j=0; j<n; j++) {
            if (a[j]!=1&&i%a[j]==1) x++;
            else if (a[j]==1) x++;
        }
    }
    cout<<x<<endl;
}
