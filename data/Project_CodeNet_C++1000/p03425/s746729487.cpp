#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    ll m = 0, a = 0, r = 0, c = 0, h = 0;
    int P[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
    int Q[10] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
    int R[10] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};
    rep(i, N){
        string S;
        cin >> S;
        if(S[0] == 'M') m++;
        if(S[0] == 'A') a++;
        if(S[0] == 'R') r++;
        if(S[0] == 'C') c++;
        if(S[0] == 'H') h++;
    }
    ll D[5];
    D[0] = m, D[1] = a, D[2] = r, D[3] = c, D[4] = h;
    ll ans = 0;
    rep(i, 10){
        ans += D[P[i]] * D[Q[i]] * D[R[i]];
    }
    cout << ans << endl;
    return 0;
}