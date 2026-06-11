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
    set<int>XA;
    rep(i, 0, N){
        int index = 0;
        cin >> index;
        XA.insert(index);
        A[index]++;
    }
    sort(A.begin(), A.end());
    long long size = 0;
    if (XA.size()>K){
        size= XA.size()-K;
    }
    ll ans = 0;
    for(int i = 0; i < A.size(); i++){
        if(size && A[i]){
            ans += A[i];
            size--;
        }
    }
    cout << ans << endl;
    return 0;
}
