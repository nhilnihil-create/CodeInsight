#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[N];
    int b[N];
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    ll need = 0;
    ll have = 0;
    ll ctA = 0;
    priority_queue<ll> pq;
    rep(i, n)
    {
        ll diff = abs(a[i] - b[i]);
        if (a[i] > b[i])
        {
            have += diff;
            pq.push(diff);
        }
        else if (a[i] < b[i])
        {
            need += diff;
            ++ctA;
        }
    }
    if (need > have)
    {
        cout << -1 << endl;
    }
    else
    {
        while (need > 0)
        {
            need -= pq.top();
            ++ctA;
            pq.pop();
        }
        cout << ctA << endl;
    }
}
