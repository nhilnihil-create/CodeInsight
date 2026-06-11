#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int x,y;
    cin>>x>>y;
    
    int ans = 1001001001;
    int cost;
    rep(i,max(x,y)+1){
        cost = 2*i*c;
        cost += max(0,x-i)*a;
        cost += max(0,y-i)*b;
        
        ans = min(ans, cost);
    }
    
    cout << ans << endl;
    
    return 0;
}