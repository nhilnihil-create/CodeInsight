#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int LL;
#define REP(n) for(LL i = 0; i < (n); i++)
#define COUT(val) cout << (val) << endl
#define CIN(val) cin >> (val)
#define SORT(vec) sort(vec.begin(), vec.end())
#define SORT_GRE(vec) sort(vec.begin(), vec.end(), greater<LL>())

int main(){
    LL n, p;
    cin >> n >> p;
    LL powNum, keeper;
    if(n == 1){
        cout << p << endl;
        return 0;
    }
    if(n >= 60){
        cout << 1 << endl;
        return 0;
    }
    for(LL i = 1; i <= 1145141919810; i++){
        powNum = pow(i, n);
        if(powNum > p){
            powNum = pow(i-1, n);
            keeper = i - 1;
            break;
        } else if(powNum == p){
            cout << i << endl;
            return 0;
        }
    }
    while(1){
        if(p % powNum == 0){
            cout << keeper << endl;
            return 0;
        } else {
            keeper--;
            powNum = pow(keeper, n);
        }
    }
    cout << 1 << endl;
    return 0;
}