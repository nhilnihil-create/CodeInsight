#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    string S;
    cin >> S;
    int count = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == 'x'){
            count++;
        }
    }
    if (count > 7){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

