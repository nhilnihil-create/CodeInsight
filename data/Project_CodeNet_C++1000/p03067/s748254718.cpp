#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A,B,C; cin >> A >> B >> C;
    cout << (A+B+C-max({A,B,C})-min({A,B,C})==C?"Yes":"No") << '\n';
}