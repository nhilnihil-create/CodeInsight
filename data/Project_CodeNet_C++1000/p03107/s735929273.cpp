#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    string S;
    cin >> S;
    int zero=0, ichi=0;
    for(auto aaa: S){
        if(aaa=='0') zero++;
        else ichi++;
    }
    cout << min(ichi, zero)*2 << endl;
    return 0;
}
