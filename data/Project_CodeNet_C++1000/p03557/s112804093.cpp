#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N),B(N),C(N);
    for ( int64_t i = 0; i < N; ++i){
        cin >> A.at(i);
    }
    for ( int64_t i = 0; i < N; ++i){
        cin >> B.at(i);
    }
    for ( int64_t i = 0; i < N; ++i){
        cin >> C.at(i);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    
    int64_t res = 0;
    for ( int64_t i = 0; i < N; ++i){
        int64_t b = B.at(i);
        // bより小さいAの要素数
        auto aitr = lower_bound(A.begin(),A.end(),b);
        int64_t a = aitr - A.begin();
        // bより大きいCの要素数
        auto citr = upper_bound(C.begin(),C.end(),b);
        int64_t c = C.end() - citr;
        //cout << "b " << b << " a " << a << " c " << c << endl;
        res = res + a * c;
    }
    
    cout << res << endl;
    return 0;
}