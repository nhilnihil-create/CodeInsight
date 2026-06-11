#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<int> box(N + 1, 0);
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        box[num]++;
    }

    sort(box.begin(), box.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < N + 1; i++)
    {
        if (box[i] == 0)
        {
            break;
        }
        else if (K > 0)
        {
            K--;
        }
        else if (K == 0)
        {
            ans += box[i];
        }
    }
    cout << ans << endl;
    return (0);
}