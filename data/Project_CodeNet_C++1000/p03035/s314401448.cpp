#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int a, b;
    cin >> a >> b;
    
    if(a >= 13)
        cout << b << endl;
    else if (a >= 6 && a <= 12)
        cout << b / 2 << endl;
    else
        cout << 0 << endl;
    
    
    return 0;
}
