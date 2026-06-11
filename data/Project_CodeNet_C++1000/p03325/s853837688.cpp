#include <iostream>
#include <vector>
using namespace std;
int div2(int x){
    int ret = 0;
    while(x%2 == 0){
        ret++;
        x /= 2;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        cnt += div2(A[i]);
    }
    cout << cnt << endl;
    return 0;
}