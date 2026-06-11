#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    char X, Y;
    cin >> X >> Y;
    char res;
    if(X > Y) res = '>';
    else if(X == Y) res = '=';
    else res = '<';
    cout << res << endl;
}