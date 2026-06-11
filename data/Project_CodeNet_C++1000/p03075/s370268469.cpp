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
    vector<int>a(5);
    for(int i=0;i<5;i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    sort(a.begin(),a.end());
    if(a[4]-a[0]>k){
        cout << ":(" << endl;
    }
    else{
        cout << "Yay!" << endl;
    }
}

int main(){
  solve();
  return 0;
}
