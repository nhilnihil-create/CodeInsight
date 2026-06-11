 #include "bits/stdc++.h"

using namespace std;

#define sp(x) cout<<setprecision(x);
#define all(a) (a).begin(), (a).end()
#define inf 10000000
#define linf INT64_MAX*0.99
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define yes "Yes"
#define no "No"
#define divs 1000000007
#define dive 1000000009
#define pi 3.141592653589793238

typedef pair<int, int> P;
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    int a, b; cin>>a>>b;
    vector<int> p(n);
    REP(i,n) cin>>p[i];
    int one = 0, two = 0, three = 0;
    REP(i,n){
        if(p[i]<=a) one++;
        else if (p[i]>a&&p[i]<=b)
        {
            two++;
        } else {
            three++;
        }
    }
    int ans = min(min(one,two),three);
    cout<<ans<<endl;
    return 0;
}