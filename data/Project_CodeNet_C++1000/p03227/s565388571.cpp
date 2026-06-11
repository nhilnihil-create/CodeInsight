#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    string S;
    cin >> S;
    if (S.size() == 2){
        cout << S << endl;
    }
    else {
        reverse(ALL(S));
        cout << S << endl;
    }
}

