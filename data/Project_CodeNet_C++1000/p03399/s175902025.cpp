#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    int res = 0;
    res += (A>B) ? B : A;
    res += (C>D) ? D : C;
    cout << res << endl;
}
