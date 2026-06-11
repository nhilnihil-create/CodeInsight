#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int N ,K;
    cin >> N >>K;
    vector<int>A(N+1, 0);
    rep(i, 0, N){
        int index = 0;
        cin >> index;
        A[index]++;
    }
    sort(A.rbegin(), A.rend());
    
    ll ans = 0;
    for(int i = 0; i < K; i++){
        ans += A[i];
    }
    ans = N - ans;
    cout << ans << endl;
    return 0;
}