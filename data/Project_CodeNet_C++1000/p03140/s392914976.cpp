#include "bits/stdc++.h"
using namespace std;

#define Rep(i,n) for(int i=0;i<n;i++)
#define For(i,n1,n2) for(int i=n1;i<n2;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define RREP(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define put(a) cout<<a<<"\n";
#define all(c)  (c).begin(),(c).end()
#define SORT(a) sort((a).begin(),(a).end())
#define TDARRAY(int,a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()

typedef long long ll;
typedef pair<int, int> P;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b){a=b;return 1;}return 0;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b){a=b;return 1;}return 0;}

int n;
string a,b,c;

int main(){
    cin >> n >> a >> b >> c;
    int res = 0;
    REP(i,n){
        vector<int> cnt(26,0);
        cnt[a[i]-'a']++;
        cnt[b[i]-'a']++;
        cnt[c[i]-'a']++;
        res+=3-*max_element(all(cnt));
    }
    put(res);
    return 0;
}
