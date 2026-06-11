//c++ テンプレ
#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())

priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


void solve(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<llint>mp(n+1,0);
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        mp[a]=1;
    }
    int res1=0,res2=0;
    for(int c=x;c>0;c--)res1+=mp[c];
    for(int c=x;c<n;c++)res2+=mp[c];
    cout << min(res1,res2) << endl;


}

int main(){
    solve();
    return 0;
}


