#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int N, sub;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    sub = A[N - 1] - A[0];
    cout << sub << endl;
}