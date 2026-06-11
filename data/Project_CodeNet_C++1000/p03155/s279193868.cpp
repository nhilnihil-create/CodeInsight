#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i = 0; i < n; i++)

int main(void)
{
    int N,W,H;
    cin >> N >> H >> W;
    cout << ((N-H+1)*(N-W+1)) << endl;
}
