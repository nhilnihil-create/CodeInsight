#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    double n, m, d;
    cin >> n >> m >> d;
    if(d != 0) cout << ((n-d)*2.0/(n*n))*(m-1) << endl;
    else cout << (n/(n*n))*(m-1) << endl;
}