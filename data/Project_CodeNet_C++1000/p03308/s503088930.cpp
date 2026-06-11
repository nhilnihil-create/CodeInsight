#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,n)cin>>a[i];
    
    sort(a.begin(), a.end());
    cout << a.back()-*a.begin() << endl;
    return 0;
}
