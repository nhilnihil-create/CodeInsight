#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    string s;
    rep(i,0,4){
        char c;
        cin>>c;
        s+=c;
    }
    sort(all(s));
    cout<<(s=="1479" ? "YES" : "NO")<<endl;
}
