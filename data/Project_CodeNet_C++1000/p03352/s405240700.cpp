#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int X;
    cin >> X;
    vector<bool> po(1000);
    po[1] = 1;
    for(int i=2; i<=31; ++i){
        int n=i;
        while(n<1000){
            n*=i;
            po[n] = 1;
        }
    }
    for(int i=X; i>0; --i){
        if(po[i]){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
