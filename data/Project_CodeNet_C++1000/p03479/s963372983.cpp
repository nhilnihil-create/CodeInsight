#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
int main(){
    long double x,y;
    cin >> x >> y;
    long double n = log2(y) - log2(x);
    cout << (int)(n + 1) << endl;
}