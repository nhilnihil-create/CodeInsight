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
    vector<int> a(n);
    vector<int> b(n);
    int suma = 0, sumb = 0;
    REP(i,n){
        cin>>a[i];
        suma+=a[i];
    }
    REP(i,n){
        cin>>b[i];
        sumb+=b[i];
    }
    if(suma<sumb) cout<<"-1"<<endl;
    else{
        vector<int> sa(n);
        int cnt = 0;
        int ans = 0;
        REP(i,n){
            sa[i]=a[i]-b[i];
            if(sa[i]<0){
                cnt+=sa[i];
                ans++;
            }
        }
        sort(all(sa),greater<int>());
        REP(i,n){
            if(cnt>=0) break;
            cnt+=sa[i];
            ans+=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}