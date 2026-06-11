#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBAG = false;

int main(){

    int n, k;
    cin >> n >> k;

    if(1 + 2 * (k - 1) <= n) cout << "YES" << endl;
    else cout << "NO" << endl;

}