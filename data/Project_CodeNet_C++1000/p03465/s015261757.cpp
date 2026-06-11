#include<bits/stdc++.h>
using namespace std;
bitset<4000010>f;
int n, x, s;
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    f[0] = 1;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        f |= f << x;
        s += x;
    }
    for(int i = (s + 1) / 2; i <=s; ++i){
        if(f[i]){
            cout << i << (char)10;
            return 0;
        }
    }
    return 0;
}