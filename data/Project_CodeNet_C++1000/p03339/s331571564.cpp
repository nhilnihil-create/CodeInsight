#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int,int>;
using vii = vector<pii>;
using vvii = vector<vii>;


int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    vi eastsum(N+1), westsum(N+1);
    westsum[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        int d = ((S[i] == 'W') ? 1 : 0);
        westsum[i+1] = westsum[i] + d;
    }
    eastsum[N] = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        int d = ((S[i] == 'E') ? 1 : 0);
        eastsum[i] = eastsum[i+1] + d;
    }
    
    int min_ninzu = N+1;
    for (int l = 0; l < N; l++)
    {
        int ninzu = westsum[l] + eastsum[l+1];
        min_ninzu = min(min_ninzu, ninzu);
    }
    cout << min_ninzu << endl;    
    
    return 0;
}