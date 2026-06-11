#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i = 0; i < n; i++)

int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;
    if((a > c && c > b) || ( a < c && c < b)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
