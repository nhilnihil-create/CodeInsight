#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

        if(a[0]!=0){
            cout << -1 << endl;
            return 0;
        }

    int now=0;
    ll ans=0;
    rep(i,n-1){
        if(a[i+1]-a[i]>1){
            cout << -1 << endl;
            return 0;
        }
        else if(a[i+1]-a[i]==1){
            ans++;
        }
        else ans+=a[i+1];
    }

    cout << ans << endl;
return 0;
}