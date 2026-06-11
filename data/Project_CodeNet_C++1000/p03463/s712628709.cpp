#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    if ((B - A) % 2 == 1) cout << "Borys" << endl;
    else cout << "Alice" << endl;
}