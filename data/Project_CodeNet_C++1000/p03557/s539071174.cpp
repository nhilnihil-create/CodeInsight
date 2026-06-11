#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main(int argc, char *argv[])
{
    
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    long long N;
    cin >> N;
    vector<long long> A(N), B(N), C(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    sort(C.begin(), C.end());
    
    long long cases = 0;
    
     for (int i = 0; i < N; i++) {
        auto lowa = lower_bound(A.begin(), A.end(), B[i]);  //B[i]以上
        auto lowc = upper_bound(C.begin(), C.end(), B[i]);  //B[i]より大きい
        long long k = lowa - A.begin();
        long long m = C.end() - lowc;
        //cout << *lowa << " " << B[i] << " " << *lowc << endl;
        //cout << k << " " << m << endl;
        cases += k * m;
    }
    
    cout << cases << endl;
    
    
    
    return 0;
}