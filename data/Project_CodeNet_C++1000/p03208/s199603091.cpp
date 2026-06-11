#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,K;
    cin >> N >> K;
    vector<int> H(N); for(int i = 0; i < N; ++i) cin >> H[i];
    sort(H.begin(), H.end());
    int ret = 1e9;
    for(int i = 0; i + K - 1 < N; ++i){
        ret = min(ret, H[i+K-1] - H[i]);
    }
    cout << ret << endl;
    return 0;
}