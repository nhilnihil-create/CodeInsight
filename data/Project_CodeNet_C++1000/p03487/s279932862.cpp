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
    vector<ll>A(N);
    map<ll, int>mp;
    ll ans = 0;
    rep(i, 0, N){
        cin >> A[i];
        mp[A[i]]++;
    }
   
    rep(i, 0, N){
        if(mp[A[i]] != A[i]){
            mp[A[i]]--;
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}
