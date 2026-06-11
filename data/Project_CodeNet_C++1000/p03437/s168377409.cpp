#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int64_t X, Y;
    cin >> X >> Y;
    if (X % Y == 0){
        cout << -1 << endl;
    }
    else {
        cout << X << endl;
    }
}


