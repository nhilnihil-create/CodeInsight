#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    int flag = 0;
    while(N >= 0) {
        if (N%7 == 0) {
            cout << "Yes" << endl;
            flag++;
            break;
        }
        N -= 4;    
    }
    if (flag == 0) {
        cout << "No" << endl;
    }
}

