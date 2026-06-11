#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    int ma = max(max(A,B),C);
    cout << pow(2,K)*ma+A+B+C-ma << endl;
}
