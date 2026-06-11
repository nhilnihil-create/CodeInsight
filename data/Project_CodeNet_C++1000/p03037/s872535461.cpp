#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N, M;
    cin >> N >> M;
    int mi = 0;
    int ma = 100001;
    rep(i, M){
        int L, R;
        cin >> L >> R;
        if(L>mi) mi = L;
        if(R<ma) ma = R;
    }
    int ans = ma-mi+1;
    cout << (ans>0 ? ans: 0) << endl;
    return 0;
}
