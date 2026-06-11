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



int main()
{
    int N,K;
    cin >> N >> K;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    int res = 1;
    int sum = K;
    while(sum < N)
    {
        res++;
        sum += (K -1);
    }
    cout << res << endl;
}