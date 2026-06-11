#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P pair<int, int>
#define rep(i,n)         for(int i=0; i<(n); i++)
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"

//----------------------------------------------------

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int A = a*10+b+c;
    int B = a+b*10+c;
    int C = a+b+c*10;
    int ans = max(A, B);
    ans = max(ans, C);
    cout << ans << endl;
}