#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int>A(N);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        while(A[i]%2 != 1) {
            ans++;
            A[i]/=2;
        }
    }
    cout << ans << endl;
}