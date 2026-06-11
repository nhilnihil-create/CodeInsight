#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;
using namespace std;

int main() {
    double n, m;
    cin >> n >> m;
    cout << (1900*m+100*(n-m))*pow(2,m) << endl;
}
