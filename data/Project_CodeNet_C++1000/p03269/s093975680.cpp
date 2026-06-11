#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;

int main(){
    int l; cin >> l;;
    int k = 0; while((1<<k) <= l) k++;
    int bit = __builtin_popcount(l) - 1;
    cout << k << " " << 2*(k-1)+bit << endl;
    int count = 1<<(k-1);
    rrep(i,k-1){
        cout << i+1 << " " << i+2 << " " << (1<<i) << endl;
        cout << i+1 << " " << i+2 << " " << 0 << endl;
        if((1<<i)&l){
            cout << i+1 << " " << k << " " << count << endl;
            count += 1<<i;
        }
    }
}