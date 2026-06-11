#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> as(n, 0);
    int N = 0;
    rep(i, n){
        cin >>  as[i];
        N = max(N, as[i]);
    }
    int r = 0;
    int ans;
    rep(i, n){
        int tmp = min(as[i], N - as[i]);
        if(r < tmp){
            ans = as[i];
            r = tmp;
        }
    }
    cout << N << " " << ans << endl;
    return 0;
}
