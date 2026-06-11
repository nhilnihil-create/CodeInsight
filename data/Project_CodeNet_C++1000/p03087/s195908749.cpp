#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<int> ruiseki(N + 1, 0);
    for (int i = 0; i < N - 1; ++i)
    {
        if (S[i] == 'A' && S[i + 1] == 'C')
        {
            ruiseki[i + 1] = ruiseki[i] + 1;
        }
        else
        {
            ruiseki[i + 1] += ruiseki[i];
        }
    }

    int left, right;
    for (int i = 0; i < Q; i++)
    {
        cin >> left >> right;
        left--;
        right--;
        cout << ruiseki[right] - ruiseki[left] << endl;
    }
    return (0);
}