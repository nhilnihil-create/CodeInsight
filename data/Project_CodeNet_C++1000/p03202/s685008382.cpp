#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll a[212345];

    cin >> n;

    REP(i, n)
    {
        cin >> a[i];
    }

    ll l = 0;
    ll r = n + 1;

    while (r - l > 1)
    {
        ll mid = (l + r) / 2;

        vector<pair<int, ll>> v;
        v.push_back(make_pair(1, a[0]));

        bool check = true;

        REP(i, n - 1)
        {
            if (a[i] < a[i + 1])
            {
                if (v[v.size() - 1].first == 1)
                    v[v.size() - 1].second += (a[i + 1] - a[i]);
                else
                    v.push_back(make_pair(1, a[i + 1] - a[i]));
            }
            else
            {
                ll num = a[i] - a[i + 1];
                while (num - v[v.size() - 1].second >= 0)
                {
                    num -= v[v.size() - 1].second;
                    v.pop_back();
                }

                v[v.size() - 1].second -= num;

                /*
                cout << "#" << i + 1 << " ";
                for (P p : v)
                {
                    printf("{%d:%d} ", p.first, p.second);
                }
                cout << endl;
                */

                if (v.size() == 1 && v[0].first == mid)
                {
                    check = false;
                    break;
                }

                pair<int, ll> p_ = make_pair(-1, -1);
                if (v[v.size() - 1].first == mid)
                {
                    p_ = v[v.size() - 1];
                    p_.first = 1;
                    v.pop_back();
                }

                pair<int, ll> p;
                p.first = v[v.size() - 1].first + 1;
                p.second = 1;

                if (v[v.size() - 1].second == 1)
                    v.pop_back();
                else
                    v[v.size() - 1].second--;

                if (v.size() && p.first == v[v.size() - 1].first)
                {
                    p.second += v[v.size() - 1].second;
                    v.pop_back();
                }

                v.push_back(p);

                if (p_.first != -1)
                {
                    v.push_back(p_);
                    if (v[v.size() - 1].first == v[v.size() - 2].first)
                    {
                        v[v.size() - 2].second += v[v.size() - 1].second;
                        v.pop_back();
                    }
                }
            }

            /*
            for (P p : v)
            {
                printf("{%d:%d} ", p.first, p.second);
            }
            cout << endl;
            */
        }

        /*
        for (P p : v)
        {
            printf("{%d:%d} \n", p.first, p.second);
        }
        cout << endl;

        cout << check << endl;
        return 0;
        */

        if (check)
            r = mid;
        else
            l = mid;
    }

    cout << r << endl;

    return 0;
}