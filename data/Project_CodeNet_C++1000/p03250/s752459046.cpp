#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    int element1 = max({A, B, C}) * 9;
    int element2 = A + B + C;
    cout << element1 + element2 << endl;
}