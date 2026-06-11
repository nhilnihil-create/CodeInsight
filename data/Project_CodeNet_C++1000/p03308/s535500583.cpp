#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;
    cin>>n;
    int a, amin = 1001001001, amax = 0;
    rep(i,n){
        cin>>a;
        amin = min(amin, a);
        amax = max(amax, a);
    }
    
    cout << amax -amin << endl;
    return 0;
}

