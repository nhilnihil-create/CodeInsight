#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<int> ind(N);
    for(int i = 0; i < N; i++) ind[i] = i;
    sort(ind.begin(), ind.end(), [&](int i, int j){
        return A[i] < A[j];
    });
    long long ans = 0;
    int i = 0;
    while(M > 0){
        if(M <= B[ind[i]]){
            ans += A[ind[i]] * M;
            M -= M;
        }
        else{
            M -= B[ind[i]];
            ans += A[ind[i]] * B[ind[i]];
        }
        i++;
    }
    cout << ans << endl;
}