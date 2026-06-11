#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);

const int MAX=200010;


int main() {
    ios_base::sync_with_stdio(false); 

    ll n;
    cin >> n;
    vector<ll> a;
    int p=1;
    while (n!=0) {
        if (abs(n%2)==1) a.push_back(1);
        else a.push_back(0);
        if (n>0) n/=-2;
        else n=(-n+1)/2;
    }
    reverse(a.begin(),a.end());
    if (a.size()==0) a.push_back(0);
    rep(i,a.size()) cout << a[i];
    cout << endl;


    
    return 0;
}
