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
    int n;
    cin >> n;
    vector<int>L(n);
    for(int i=0;i<n;i++)cin >> L[i];
    sort(L.begin(),L.end());
    int x=L[n-1];
    int y=0;
    for(int i=0;i<n-1;i++)y+=L[i];
    if(y>x)cout << "Yes";
    else cout << "No";
    cout << endl;
}

int main(){
    solve();
    return 0;
}


