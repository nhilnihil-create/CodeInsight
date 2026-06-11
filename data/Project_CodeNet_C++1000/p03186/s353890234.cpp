#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A + B < C){
        cout << 2 * B + A  + 1 << endl;
    }
    else {
        cout << C + B << endl;
    }
}

