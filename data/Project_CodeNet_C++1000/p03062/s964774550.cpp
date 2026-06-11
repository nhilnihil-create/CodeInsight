#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    int cnt = 0, mn = 1001001001;
    ll sum = 0;
    rep(i,n) {
        int a;
        cin >> a;
        sum += abs(a);
        mn = min(abs(a),mn);
        if(a < 0) {
            cnt++;
        }
    }
    
    if(cnt % 2 == 1)
        sum -= mn * 2;
    
    cout << sum << endl;
    
    
    
    return 0;
}
