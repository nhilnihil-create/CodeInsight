#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <stack>
#include <queue>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using ld = long double;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, i, a[10001], b[10001], c[10001], sum1=0, sum2=0;

    cin >> N;
    for(i=1; i<=N; i++){
        cin >> a[i];
    }
    for(i=1; i<=N; i++){
        cin >> b[i];
        c[i] = b[i]-a[i];
    }

    for(i=1; i<=N; i++){
        if(c[i]>0) sum1 += c[i]/2;
        else sum2 += c[i];
    }

    if(sum1+sum2>=0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}