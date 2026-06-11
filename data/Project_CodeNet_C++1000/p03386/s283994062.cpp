#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = a; i <= min(b, a+k-1); i++) cout << i << endl;
    for (int i = max(b-k+1, a+k); i <= b; i++) cout << i << endl;
}