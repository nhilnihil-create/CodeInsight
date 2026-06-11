#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int a, b;
    cin >> a >> b;
    bool flg = false;
    for(int i=1; i<4; i++){
        if(a * b * i % 2 == 1) flg = true;
    }
    if(flg) out("Yes");
    else out("No");
}