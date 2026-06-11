#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    int d;
    cin >> d;
    if(d == 25) cout << "Christmas";
    else if(d == 24) cout << "Christmas Eve";
    else if(d == 23) cout << "Christmas Eve Eve";
    else cout << "Christmas Eve Eve Eve";
    return 0;
}