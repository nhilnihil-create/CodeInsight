#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int a, b;
    cin >> a >> b;
    int diff = b -  a;

    int B=0;
    for (int i=1; i<=diff; i++){
        B += i;
    }
    out(B-b);
}