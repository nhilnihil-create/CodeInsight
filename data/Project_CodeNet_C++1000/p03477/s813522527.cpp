#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
    ll A, B, C, D; cin >> A >> B >> C >> D;
    if(A+B < C+D) cout << "Right" << endl;
    else if(A+B>C+D) cout << "Left" << endl;
    else cout << "Balanced" << endl;

}