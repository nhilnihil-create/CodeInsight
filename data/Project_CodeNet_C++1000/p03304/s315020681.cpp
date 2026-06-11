#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iomanip>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll n,m,d;
    cin >> n >> m >> d;
    ll c =  n - d;//条件を満たす組
    ll mul = 1;
    if(d != 0){
        mul = 2;
    }

    float result = (float)(n - d) * (float)(m - 1) * (float)mul / (float)(n * n);
    cout << setprecision(10) << result << endl;
}
