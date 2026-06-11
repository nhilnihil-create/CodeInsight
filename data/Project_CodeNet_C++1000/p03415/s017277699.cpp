#include<string>
#include<iostream>
#include <algorithm>
#include<vector>
#include<functional>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <numeric>
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
using namespace std;



int main() {
    vector<string> c(3);
    rep(i, 3) cin >> c.at(i);
    cout << c[0][0] << c[1][1] << c[2][2] << endl;
    return 0;
}
