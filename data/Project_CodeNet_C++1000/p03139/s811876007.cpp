#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, A, B;
    cin >> N >> A >> B;
    cout << min(A, B) << " " << max(min(A, B) - N + max(A, B), 0);
}

