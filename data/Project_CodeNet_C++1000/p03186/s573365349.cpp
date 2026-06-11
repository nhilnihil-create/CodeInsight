#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    ll gedoku = A + B;
    ll doku = C;
    if (doku - 1 <= gedoku){
        cout << B + C << endl;
    }
    else{
        cout << A + 2 * B + 1 << endl;
    }
}

