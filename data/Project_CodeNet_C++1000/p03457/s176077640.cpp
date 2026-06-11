#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main()
{
    int N;
    cin >> N;
    int t[N + 1],x[N + 1],y[N + 1];
    t[0] = 0, x[0] = 0,y[0] = 0;
    for(int i = 1; i < N + 1; i++) cin >> t[i] >> x[i] >> y[i];
    for(int i = 0; i < N; i++)
    {
        if(abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]) > t[i + 1] - t[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 0; i < N; i++)
    {
        if( ( (t[i + 1] - t[i]) - abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]) ) % 2 != 0 )
        {
            cout << "No" << endl;
            return(0);
        }
    }
    cout << "Yes" << endl;
}