#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

int main(){
    int n; cin >> n;
    map<int, int> p;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(p.count(a)) p[a]++;
        else p[a]=1;
    }
    ll ans = 0;
    for(auto q:p){
        int x=q.first, y=q.second;
        if(x>y) ans += y;
        else ans += y-x;
    }
    cout << ans << endl;
}