#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;


int main(){ 
    int a, b;
    cin >> a >> b;
    int x = 0;
    for (int i=1;i< b - a; i++) x += i;
    cout << x - a << "\n";
    return 0;
}
