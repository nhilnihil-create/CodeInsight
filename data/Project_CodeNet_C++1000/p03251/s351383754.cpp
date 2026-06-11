#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <limits.h>
 
#define YesNo(b) ((b) ? "Yes" : "No")
#define YESNO(b) ((b) ? "YES" : "NO")

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;



int main()
{
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vi x(N), y(M);
    for (int i = 0; i < N; i++)
        cin >> x[i];
    for (int i = 0; i < M; i++)
        cin >> y[i];
    
    int maxX = *max_element(begin(x), end(x));
    int minY = *min_element(begin(y), end(y));
    
    maxX = max(maxX, X);
    minY = min(minY, Y);

    bool ans = (maxX < minY);
    cout << (ans ? "No War" : "War") << endl;
}
