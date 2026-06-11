#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<int>;
using P  = pair<ll,ll>;

int main(){
    v a(5);
    rep(i,5)cin>>a[i];
    int k; cin>>k;
    if(a[4]-a[0]>k)
        cout << ":(" << endl;
    else
        cout << "Yay!" << endl;
    
    return 0;
}