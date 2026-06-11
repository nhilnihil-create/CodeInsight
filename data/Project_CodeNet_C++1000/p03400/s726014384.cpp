#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,D,X;
    cin >> N >> D >> X;
    vector<int> A(N); for(int i = 0; i < N; ++i) cin >> A[i];
    int ans = X;
    for(int i = 0; i < N; ++i){
        for(int j = 0;; ++j){
            if(j*A[i] + 1 > D) break;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}