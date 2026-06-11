#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int a,b,x;
    cin >> a >> b >> x;
    bool hantei=true;

    if(a+b<x || a>x) hantei =false;
    if(hantei) cout << "YES" << endl;
    else        cout << "NO" << endl;
}