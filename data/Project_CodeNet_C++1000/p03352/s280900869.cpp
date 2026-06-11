#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
int x;
bool isbeki[1010];

int main() {
    cin >> x;
    isbeki[1] = true;
    for (int i = 2;i<=1000; i++) {
        for (int j = 2; pow(i, j) <= 1000; j++) {
            isbeki[(int)pow(i, j)] = true;
        }
    }
    for (int i=x; i >= 0; i--) {
        if (isbeki[i]) {
            cout << i << endl;
            return 0;
        }
    }
}