#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int in0, in1;
    cin >> in0 >> in1;
    ll n = max(in0, in1);
    ll m = min(in0, in1);
    if(n == 1 && m == 1){
        cout << 1 << endl;
    }else if(m == 1){
        cout << n-2 << endl;
    }else{
        cout << n*m - 2*n - 2*m + 4 << endl;
    }
    return 0;
}