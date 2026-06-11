#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c = 0;
    cin >> a >> b;
    for (int i = a ; i <= b ; i++) if (i / 10000 == i % 10 && ( i / 1000 ) % 10 == ( i % 100 ) / 10) c++;
    cout << c;	
}
