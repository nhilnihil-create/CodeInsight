#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    vector<int> A(10);
    for (int i = 0; i < 4; i++){
        int a;
        cin >> a;
        A.at(a)++;
    }
    if (A.at(1) && A.at(4) && A.at(7) && A.at(9)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

