
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int r, d, x;
    cin >> r >> d >> x;
    int now = r*x-d;
    //2001年
    cout << now << endl;
    //2002年から2010年
    for(int i=0; i<9; i++){
        now = r*now - d;
        cout << now << endl;
    }
    return 0;
}