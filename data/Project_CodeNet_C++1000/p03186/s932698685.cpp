#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t A, B, C;
    cin >> A >> B >> C;
    if(C > A + B) cout << 2 * B + A + 1 << endl;
    else cout << B + C << endl;
}