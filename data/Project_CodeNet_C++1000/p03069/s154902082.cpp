#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<int,int>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

signed main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=200000+1;
    bool ok=0;
    int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    for(int i=0;i<n;i++){
        if(s[i]=='#'){
            ok=1;
            cnt1++;
        }
        else cnt2++;
        if(ok&&s[i]=='.') cnt3++;
    }
    chmin(ans,cnt1);
    chmin(ans,cnt3);
    ok=0;
    int cnt=0;
    for(int i=0;i<=n;i++){
        if(s[i]=='#'){
            ok=1;
            chmin(ans,cnt3-cnt4+cnt);
            //chmin(ans,cnt3-cnt4+);
            cnt++;
        }else{
            if(ok) cnt4++;
        }
    }
    cout<<ans<<endl;
}