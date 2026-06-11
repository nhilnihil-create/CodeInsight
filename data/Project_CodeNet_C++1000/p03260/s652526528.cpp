#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int a,b,c;
    cin >> a >> b;
    if (a*b % 2 == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}