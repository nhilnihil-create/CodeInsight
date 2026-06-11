#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
signed main(void){
    int n; cin>>n;
    vector <int> a(n); 
    map <int,int> ma;
    rep(i,n) {cin>>a[i]; ma[a[i]]++;}
    sort(a.begin(),a.end());
    int ans = 0;
    rrep(i,n){
        int now = a[i];
        if(ma[now] == 0) continue;
        int goal = 1LL;
        while(now>=goal) goal*= 2LL;
        int need = goal - a[i];
        if(a[i] == need){
            if(ma[need]>=2) ma[need]-=2, ans += 1;
        }else if(ma[goal-a[i]]) ma[goal-a[i]]--, ma[now]--, ans += 1; 
    }
    cout<<ans<<endl;
}
