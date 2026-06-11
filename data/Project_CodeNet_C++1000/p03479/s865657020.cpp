#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;
using namespace std;

int main() {
    int64_t x, y;
    cin >> x >> y;
    int n=0;
    int64_t z=y/x;
    while (z) {
        z/=2;
        n++;
    } 
    cout << n << endl;
}