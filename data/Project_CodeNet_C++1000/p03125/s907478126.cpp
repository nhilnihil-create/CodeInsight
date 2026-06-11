#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define vsort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())

const int MOD = 1000000007;
const int INF = INT_MAX;


int main(){

    int a, b;
    cin >> a >> b;

    if (b%a == 0) cout << a+b << endl;
    else cout << b-a << endl;
}





//              g++ -std=c++1z