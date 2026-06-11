#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin>>s;
    int sz = s.size();
    int l=1, r=sz+1; //L OK, R NG
    while(r-l>1){
        int mid = (l+r)/2;
        bool f0=false,f1=false;
        rep(i,2*mid-sz){
            int j = sz-mid+i;
            if (s[j]=='0') f0 = true;
            if (s[j]=='1') f1 = true;
        }
        if (f0&&f1){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<l<<endl;
    return 0;
}
