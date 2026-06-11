#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    int N;
    cin >> N;
    valarray<i64> A(N), B(N), C;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    i64 upper = B.sum() - A.sum();
    i64 ope = (B - A).apply([](i64 x){ return max((x+1)/2, 0l); }).sum();
    if(ope > upper) cout << "No" << endl;
    else cout << "Yes" << endl;
}
