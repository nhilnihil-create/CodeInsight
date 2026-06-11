#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<int>H(N);
 
    rep(i, 0, N){
        cin >> H[i];
    }
    ll ans = 0;
    ll preN = 0;
    rep(i, 0, N){
        if(preN >= H[i]){
            preN = H[i];
        } else {
            ans += H[i]-preN;
            preN = H[i];
        }
    }
    
    cout << ans << endl;
    return 0;
}
