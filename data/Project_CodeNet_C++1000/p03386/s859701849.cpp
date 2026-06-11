#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int a,b,k,mini=0,max=0;
    cin>>a>>b>>k;
    set<int> ans;
    for (int i=a; i<a+k; i++) {
        if (a<=i&&i<=b) ans.insert(i);
    }
    for (int i=b-k+1; i<=b; i++) {
        if (a<=i&&i<=b) ans.insert(i);
    }
    for (auto v: ans) cout<<v<<endl;
}
