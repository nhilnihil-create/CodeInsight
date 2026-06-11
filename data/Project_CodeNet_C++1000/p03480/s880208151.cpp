#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <cmath>
using namespace std;
using Int = long long;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n,m) for(int i=n;i<m;i++)
int main()
{
    string S; cin >> S;
    int N = S.size();
    int r = S.size();
    REP(i, N-1) if (S[i] != S[i+1]) r = min(r, max(i+1, N-i-1));
    cout << r << endl;
    return 0;
}