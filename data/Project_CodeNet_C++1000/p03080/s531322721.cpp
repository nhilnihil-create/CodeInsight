#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, R = 0, B = 0;
    string s;
    cin >> N >> s;
    for (int i = 0; i < N; i++){
        if (s.at(i) == 'R'){
            R++;
        }
        else {
            B++;
        }
    }
    if (R > B){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

