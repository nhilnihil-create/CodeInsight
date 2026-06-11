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
    int N;
    cin >> N;

    vector<int> X(N);
    int sub[N];
    int B[N];
    for(int i = 0; i < N; i++) cin >> X[i], sub[i] = X[i];
    sort(X.begin(),X.end());
    int a,b;
    a = X[N/2 - 1];
    b = X[N/2];
    for(int i = 0; i < N; i++)
    {
        if(sub[i] <= a )B[i] = b;
        else if(sub[i] >= b) B[i] = a;
    }
    for(int i = 0; i < N; i++)
    {
        cout << B[i] << endl;
    }

}