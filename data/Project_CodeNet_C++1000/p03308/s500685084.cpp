#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> A(N);
    for(long long i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    cout << A.at(N - 1) - A.at(0) << endl;
    return 0;
}