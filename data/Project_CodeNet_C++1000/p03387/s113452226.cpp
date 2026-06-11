#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    
    int n[3];
    cin >> n[0];
    cin >> n[1];
    cin >> n[2];

    sort(n, n + 3);

    int diff = 2 * n[2] - n[1] - n[0];
    if(diff % 2  == 0){
        cout << diff / 2 << endl;
    } else {
        cout << ((diff + 1) / 2 ) + 1 << endl;
    }

    return 0;
}
    