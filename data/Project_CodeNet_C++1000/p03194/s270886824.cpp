#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define endl "\n";
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define POSITIVE_INFINITY 9223372036854775807
#define NEGATIVE_INFINITY -9223372036854775807
#define MOD 1000000007

const int N = 1000002;
bool prime[N + 2];
vector<int>ar;
int sz = -1;

void F()
{
    prime[0] = true;
    prime[1] = true;

    for (int i = 4; i <= N; i += 2)
        prime[i] = true;
    for (int i = 3; i * i <= N; i += 2)
    {
        if (!prime[i])
        {
            for (int j = (i * i); j <= N; j += (i << 1))
                prime[j] = true;
        }
    }
    ar.push_back(2);

    for (int i = 3; i <= N; i += 2)
    {
        if (!prime[i])
            ar.push_back(i);
    }
    sz = ar.size();
}

int main()
{
    FASTER;
    F();
    ll n, p;
    cin >> n >> p;
    ll ans = 1;
    if (n == 1)
    {
        cout << p << endl;
        return 0;
    }

    vector<pair<long, long>> v;
    for (int i = 0; ar[i] * ar[i] <= p && i < sz; i++)
    {
        if (p % ar[i] == 0)
        {
            ll cnt = 0;
            while (p % ar[i] == 0)
            {
                cnt++;
                p /= ar[i];
            }
            
            cnt /= n;
            while (cnt--)
            {
                ans *= ar[i];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
