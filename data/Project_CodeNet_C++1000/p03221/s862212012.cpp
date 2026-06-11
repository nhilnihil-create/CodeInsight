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

int N,M;
vector<int> P,Y;

int main()
{
    cin >> N >> M;
    P.resize(M),Y.resize(M);
    for(int i = 0; i < M; i++) cin >> P[i] >> Y[i], P[i]--;

    vector<vector<int> > vals(N);
    for(int i = 0; i < M; i++) vals[P[i]].push_back(Y[i]);

    for(int v = 0; v < N; v++)
    {
        sort(vals[v].begin(),vals[v].end());
    }

    for (int i = 0; i < M; ++i) {
        int v = P[i];
        printf("%06d", v + 1);


        int id = lower_bound(vals[v].begin(), vals[v].end(), Y[i]) - vals[v].begin();
        printf("%06d\n", id + 1);
    }
}