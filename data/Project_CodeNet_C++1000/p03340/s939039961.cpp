#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;
 

vector<int> binary(int a, int n) {
    vector<int> bit(n);
    rep(i,n) {
        bit[i]=a%2;
        a/=2;
    }
    return bit;
}


bool isflag(vector<int> sum, vector<int> p) {
    bool flag=1;
    rep(i,sum.size()) {
        if (sum[i]+p[i]==2) flag=0;
    }
    return flag;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> b;
    int ain;
    rep(i,n) {
        cin >> ain;
        vector<int> bit=binary(ain,20);
        b.push_back(bit);
    }
    ll ans=0;
    vector<int> now(20);
    int right=0;
    rep(left,n) {
        while (right<n && isflag(now,b[right])) {
            rep(i,20) now[i]+=b[right][i];
            ++right;
        }
        ans+=right-left;
        if (left==right) ++right;
        else {
            rep(i,20) now[i]-=b[left][i];
        }
    }
    cout << ans << endl;
}