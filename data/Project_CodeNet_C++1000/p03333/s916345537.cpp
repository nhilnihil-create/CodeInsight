#include<bits/stdc++.h>
#define PI acos(-1.0)
#define pb push_back
#define F first
#define S second
#define debug puts
#define setp cout << fixed << setprecision(15)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int N=3e5+5;
const int MOD=998244353;
 
int main(void){
    FAST_IO;
    int n;
    cin >> n;
    vector<int> l(n+1),r(n+1);
//    cout << a[0]<<endl;
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >>b;
        l[i]=a,r[i]=b;
    }
    sort(l.rbegin(),l.rend());
    sort(r.begin(),r.end());
    ll ans=0;
    for(int i=0;i<=n;i++){
        if(l[i]>r[i]){
            ans+=2*(l[i]-r[i]);
        }
    }
    cout << ans << endl;
 
    return 0;
}
