#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;


int main(){
    int a, b; cin >> a >> b;

    int d = b-a;

    int h = 0;
    rep1(i,d) h += i;
    cout << h-b << endl;
}