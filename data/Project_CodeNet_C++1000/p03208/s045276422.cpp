#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> c(n);
    rep(i, 0, n){
        cin>>c[i];
    }
    sort(c.begin(), c.end());
    int ans = 1000000001;
    rep(i, 0, n-k+1){
        ans = min(c[i+k-1]-c[i], ans);
    }
    
    cout << ans << endl;
    return 0;
}