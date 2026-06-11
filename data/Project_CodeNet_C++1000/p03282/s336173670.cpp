#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
#define day 500000000000

int pow(ull a, ull n) {
  if (n == 0) return 1;
  if (n == 1) return a ;
  if (n % 2 == 1) return (a * pow(a, n - 1));
  ll t = pow(a, n / 2);
  return (t * t);
}

int main(){
    string S;
    cin >> S;
    ull K;
    cin >> K;

    int ans, i = 0;
    while (true) {
        if (S.at(i) != '1') {
            ans = S.at(i) - '0';
            break;
        } else {
            if (i >= K - 1) {
                ans = S.at(i) - '0';
                break;
            } else {
                i++;
                continue;
            }
        }
    }
    
    /*ull tmp = 0;
    int ans, i = 0;
    while (tmp < K || i < S.length()) {
        cout <<  tmp << endl;
        ans = S.at(i) - '0';
        tmp += pow(ans, day);
        i++;
    }*/

    cout << ans << endl;
    return 0;
}
