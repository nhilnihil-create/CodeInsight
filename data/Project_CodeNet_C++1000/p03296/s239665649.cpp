#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    int cnt = 0;
    int C = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(i != 0 && A[i - 1] == A[i]){
            cnt++;
            A[i] = C;
            C--;
        }
    }
    
    cout << cnt << endl;
}