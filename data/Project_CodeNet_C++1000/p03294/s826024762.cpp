#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> A(N);
    int ret = 0;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        ret += A[i]-1;
    }
    cout << ret << endl;
    return 0;
}