
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int a, b, x;
    cin >> a >> b >> x;
    if(a>x){
        cout << "NO" << endl;
        return 0;
    }
    if(a+b<x){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}