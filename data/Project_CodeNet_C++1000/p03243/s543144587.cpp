#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    ll tmp = N / 111;
//    cout << tmp << endl;
    if (N % 111) {
        tmp++;
    }
    cout << tmp << tmp << tmp << endl;



}
