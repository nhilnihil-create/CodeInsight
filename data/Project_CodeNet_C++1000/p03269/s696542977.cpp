#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

signed main(){
    int L;
    cin >> L;
    int N=0;
    int pow=1;
    while(pow<=L) pow *= 2, N++;
    int M = (N-1)*2 + __builtin_popcount(L) -1;
    cout << N << " " << M << endl;
    for(int i=0;i<N-1;i++) {
        cout << i+1 << " " << i+2 << " " << 0 << endl;
        cout << i+1 << " " << i+2 << " " << (1<<i) << endl;
    }
    int cur=1<<(N-1);
    for(int i=N-2;i>=0;i--) {
        if(L&(1<<i)) {
            cout << i+1 << " " << N << " " << cur << endl;
            cur += (1<<(i));
        }
    }
    return 0;
}