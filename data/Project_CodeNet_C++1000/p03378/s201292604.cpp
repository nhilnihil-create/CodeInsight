#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(M);
    for (int i=0; i<M; i++){
        cin >> A[i];
    }
    int ans;
    sort(begin(A), end(A));
    for (int i=0; i<M; i++){
        if (A[i] < X) continue;
        ans = min(i, M-i);
        break;
    }
    cout << ans << endl;
}