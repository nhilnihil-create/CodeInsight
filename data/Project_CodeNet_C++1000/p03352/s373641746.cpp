#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int X; cin >> X;
    vector<int> table(1010,0);
    table[1] = 1;
    FOR(i,2,X){
        int num = i;
        while(num*i<=X){
            num *= i;
            table[num] = 1;
        }
    }

    REPR(i,X){
        if(table[i] == 1){
            cout << i << endl;
            break;
        }
    }
    return 0;
}