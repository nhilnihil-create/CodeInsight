#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
 
using namespace std;
typedef long long ll;
const ll INF = 1e18;

# define rep(i, n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(ll i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(ll i=((int)(n)); i>0; --i)
# define all(x) (x).begin(), (x).end()
# define pb push_back
 
ll N;

ll findSumOfDigits(ll n);
ll findSumOfDigits(ll n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    ll min = INF;
    
    reps(i,N-1) {
        // A+B = N
        // B = N -A
        ll j = N - i;
        
        ll sumOfDigitsOfA = findSumOfDigits(i);
        ll sumOfDigitsOfB = findSumOfDigits(j);
        ll s = sumOfDigitsOfA + sumOfDigitsOfB;
        if (min > s) {
            min = s;
        }
    }
    
    cout << min << endl;
    
    return 0;
}
