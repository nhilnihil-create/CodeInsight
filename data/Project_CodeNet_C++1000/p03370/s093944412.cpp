#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,x;
    cin>>n>>x;
    
    int sum = 0, mmin = 1200, m;
    rep(i,n){
        cin>>m;
        sum += m;
        mmin = min(mmin, m);
    }
    x -= sum;
    
    cout << n + x/mmin << endl;
    return 0;
}