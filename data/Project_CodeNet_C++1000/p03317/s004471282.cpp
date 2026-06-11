#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    int ret = 0;
    if(N - K <= 0){
        cout << 1 << endl;
        return 0;
    }
    else {
        N -= K;
        ret++;
        while(N > 0){
            ret++;
            N -= K-1;
        }
    }
    cout << ret << endl;
    return 0;
}