#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;
typedef pair<int,int> P;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())


priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }



void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>s(m);
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        s[i].resize(k);
        for(int j=0;j<k;j++){
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<int>p(m);
    for(int i=0;i<m;i++)cin >> p[i];
    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        bool f=true;
        for(int i=0;i<m;i++){
            int c=0;
            for(int d:s[i]){
                if(bit & (1<<d))c++;
            }
            c%=2;
            if(c!=p[i])f=false;
        }
        if(f)ans++;
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}



