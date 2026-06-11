#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int d, n;
    cin >> d >> n;
    if(d==0) {
        if(n==100){ cout << 101 << endl; return 0;}
        cout << n << endl;
    }
    else if(d==1){
        if(n==100){ cout << 10100 << endl; return 0;}
        cout << 100*n << endl;
    }
    else {
        if(n==100) {
             cout << 1010000 << endl; 
             return 0;
        }
        cout << 10000*n << endl;
    }
    return 0;
}
