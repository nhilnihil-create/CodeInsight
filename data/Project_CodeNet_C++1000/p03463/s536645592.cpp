#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, A, B;
    cin >> N >> A >> B;
    if ((B - A) % 2 == 1){
        cout << "Borys" << endl;
    }
    else {
        cout << "Alice" << endl;
    }
}


