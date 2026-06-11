#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int a,b;
    cin >> a >>b;
    if(a<6) b=0;
    else if(a>=6 && a<=12) b /=2;

    cout << b << endl;

}
