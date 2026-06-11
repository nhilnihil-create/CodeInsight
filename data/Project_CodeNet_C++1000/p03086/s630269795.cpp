#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())
#define count(v,x) count(v.begin(),v.end(),x)
#define find(v,x) find(v.begin(),v.end(),x)


priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

void solve(){
    string s;
    cin >> s;
    int ans=0;
    int len=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'|| s[i]=='C' || s[i]=='G' || s[i]=='T'){
            len++;
            ans=max(len,ans);
        }
        else{
            len=0;
        }
    }
    cout << ans << endl;

}

int main(){
    solve();
    return 0;
}



