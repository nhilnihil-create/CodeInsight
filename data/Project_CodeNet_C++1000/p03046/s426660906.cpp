#include <bits/stdc++.h>
using namespace std;
int m,k;
int fac[31];
int main(){
    fac[0] = 1;
    for(int i = 1;i <= 30;++i){
        fac[i] = fac[i-1] * 2;
    }
    cin >> m >> k;
    if(m == 1 && k == 1)
        cout << "-1\n";
    else if(fac[m] - 1 < k) cout << "-1\n";
    else if(m == 1 && k == 0)
        cout << "0 0 1 1\n";
    else{
        for(int i = 0;i <= fac[m] - 1;++i){
            if(i == k)continue;
            cout << i << " ";
        }
        cout << k << " ";
        for(int i = fac[m]-1;i >= 0;--i){
            if(i == k)continue;
            cout << i << " ";
        }
        cout << k << "\n";
    }
    return 0;
}