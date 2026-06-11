#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    if(a+b>c+d) cout<<"Left"<<endl;
    else if(a+b<c+d) cout<<"Right"<<endl;
    else cout<<"Balanced"<<endl;
}