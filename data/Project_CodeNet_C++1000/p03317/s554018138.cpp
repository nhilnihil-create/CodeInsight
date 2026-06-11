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
    int N,K;
    cin >> N >> K;
    int input[N];
    rep0(i,N){
        cin >> input[i];
    }
    int res = 1;
    N-=K;
    res += (N+K-2)/(K-1);
    cout << res << endl;
}
