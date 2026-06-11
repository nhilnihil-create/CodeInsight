#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main( ) {
    //freopen("B.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,k;
    cin >> a >> b >> k;
    if (a+k-1 >= b-k+1){//output all
        rep(i,a,b+1) cout<<i<<endl;
    }
    else{
        rep(i,a,a+k) cout<<i<<endl;
        rep(i,b-k+1,b+1) cout<<i<<endl;
    }
    return 0;
}