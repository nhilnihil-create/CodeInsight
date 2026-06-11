#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    string s;
    cin >> s;
    ll a[4];
    for (int i = 0; i < 4; i++){
        a[i] = s[i] - '0';
    }

    for (int bit = 0; bit < (1 << 3); bit++){
        ll hoge = a[0];
        for (int i = 0; i < 3; i++){
            if(bit & (1<<i)){
                hoge += a[i + 1];
            }
            else
            {
                hoge -= a[i + 1];
            }
        }
        if(hoge == 7){
          for (int i = 0; i < 4; i++){
            cout << a[i];
            if(i !=3){
              if (bit & (1 << i)) cout << "+";
              else cout << "-";
            }
          }
          cout << "=7" << endl;
          return 0;
        }
    }
    return 0;
}