#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    string res;
    if(A+B>C+D) res = "Left";
    else if(A+B==C+D) res = "Balanced";
    else res = "Right";

    cout << res << endl;
}