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

int main(){
    int N;
    cin >> N;
    vector<int> A(N + 1);
    A[0] = 0;
    for(int i = 1; i < N+1; i++) cin >> A[i];

    ll sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += abs(A[i] - A[i+1]);
    }
    sum += abs(A[N] - A[0]);
    for(int i = 1; i < N; i++)
    {
        sum = sum - abs(A[i- 1] - A[i]) - abs(A[i] - A[i + 1]) + abs(A[i - 1] - A[i + 1]);
        cout << sum << endl;
        sum = sum + abs(A[i- 1] - A[i]) + abs(A[i] - A[i + 1]) - abs(A[i - 1] - A[i + 1]);
    }
    sum = sum - abs(A[N] - 0) - abs(A[N - 1] - A[N]) + abs(A[N - 1] - 0);
    cout << sum << endl;
}