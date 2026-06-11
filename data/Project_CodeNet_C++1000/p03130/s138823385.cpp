#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i = 0; i < n; i++)

int main(void)
{
    int a[10],w;
    int m = 0;
    REP(i,6) a[i] = 0;
    REP(i,6) {
        cin >> w;
        a[w] ++;
        m = max(m,a[w]);
//        cout << i <<" " << w << " " << m<< endl;
    }
    if(m >= 3) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
