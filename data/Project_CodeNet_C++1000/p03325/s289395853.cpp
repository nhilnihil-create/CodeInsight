#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A.at(i);

    int ans = 0;

    for(int i=0; i<N; ++i){
        while(A[i] % 2 == 0){
            A[i] /= 2;
            ans++;
        }
    }
    cout << ans << endl;
}