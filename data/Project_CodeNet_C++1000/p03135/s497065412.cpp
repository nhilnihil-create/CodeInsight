#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n)         for(int i=0; i<(n); i++)
#define P pair<int, int>
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"

//----------------------------------------------------

const int INF = 100100100;
int a[12][12];

int main(){
    double t, x, ans;
    cin >> t >> x;
    ans = t / x;
    prtd(10, ans);
}