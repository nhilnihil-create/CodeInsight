#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, X, sum = 0;
    cin >> N >> X;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        sum += A.at(i);
    }
    sort(A.begin(), A.end());
    cout << N + (X - sum) / A.at(0) << endl;
    return 0;
}