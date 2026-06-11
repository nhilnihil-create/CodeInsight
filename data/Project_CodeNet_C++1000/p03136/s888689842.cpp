#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;cin>>n;
    
    vi l(n);
    rep(i,n)cin>>l[i];
    sort(l.begin(), l.end());
    
    int sum = 0;
    rep(i,n-1)sum+=l[i];
    
    cout << (sum>l[n-1]?"Yes":"No") << endl;
    
    return 0;
}