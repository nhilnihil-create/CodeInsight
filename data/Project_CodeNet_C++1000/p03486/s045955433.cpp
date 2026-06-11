//c++ テンプレ
#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


void solve(){
    string s,t;
    cin >> s >> t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    int n=min(s.size(),t.size());
    for(int i=0;i<n;i++){
        if(s[i]<t[i]){
            cout << "Yes" << endl;
            return;
        }
    }
    if(s[n-1]==t[n-1] && s.size()<t.size())cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
  solve();
  return 0;
}
