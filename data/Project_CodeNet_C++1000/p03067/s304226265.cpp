#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if ((A < C && C < B) || (B < C && C < A)){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

