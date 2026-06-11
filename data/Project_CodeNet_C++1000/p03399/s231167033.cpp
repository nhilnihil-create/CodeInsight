#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n) + 1; i++)
#define all(vecto) vecto.begin(), vecto.end()
#define max3(a, b, c) max(a, max(b, c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;

void ans(bool qus){
    if (qus == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

void Ans(bool qust){
    if (qust == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

////////////////---START---////////////////

void solve(int a, int b, int c, int d){
    cout << min(a, b) + min(c, d) << endl;
}

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    solve(a, b, c, d);
}