#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    ll N;
    cin >> N;
    vector<long long> M(6, 0);
    vector<long long> Run(5);
    ll minR = 100000000000000001;
    int mindex = 0;
    rep(i, 0, 5){
        cin >> Run[i];
        if (minR > Run[i]){
            minR = Run[i];
            mindex = i;
        }
    }
    ll ans = 0;
    if (N%minR){
        ans += N/minR+1;
    } else {
        ans += N/minR;
    }
    ans += 4;
    cout << ans << endl;
    
    return 0;
}