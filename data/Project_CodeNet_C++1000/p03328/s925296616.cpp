#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a , b , x = 0;
    cin >> a >> b;
    for( int i = 1 ; i < b - a ; i++ ) x += i;
    cout << x - a;
}
