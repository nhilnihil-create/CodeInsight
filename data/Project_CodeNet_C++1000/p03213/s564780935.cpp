#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define allpt(v) (v).begin(), (v).end()


const int mod = 1e9 + 7;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(vector<T> v)
{
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}

void shave(vector<int> &v, int n)
{
    vector<int> x, y;
    int n_sq = sqrt(n) + 1;
    for (int i = 3; i < n + 1; i += 2)
    {
        x.push_back(i);
    }
    for (int i = 3; i < n_sq; i += 2)
    {
        for (auto itr = x.begin(); itr != x.end(); itr++)
        {
            if (*itr == i || *itr % i != 0)
                y.push_back(*itr);
        }
        x.clear();
        x = y;
        y.clear();
    }
    if (n >= 2)
        x.insert(x.begin(), 2);

    for (auto itr = x.begin(); itr != x.end(); itr++)
    {
        v.push_back(*itr);
    }
}

int get756(vector<int> const &v)
{
    int n = v.size();
    
    int a, b, c, ret;
    ret = 0;
    rep(i, n - 2) rep2(j, i + 1, n - 1) rep2(k, j + 1, n)
    {
        if (v[i] >= 4 && v[j] >= 4 && v[k] >= 2)
            ret++;
        if (v[i] >= 4 && v[j] >= 2 && v[k] >= 4)
            ret++;
        if (v[i] >= 2 && v[j] >= 4 && v[k] >= 4)
            ret++;
    }

    rep(i, n - 1) rep2(j, i + 1, n)
    {
        if (v[i] >= 14 && v[j] >= 4)
            ret++;
        if (v[i] >= 4 && v[j] >= 14)
            ret++;
        if (v[i] >= 24 && v[j] >= 2)
            ret++;
        if (v[i] >= 2 && v[j] >= 24)
            ret++;
    }

    if (v[0] >= 74) ret++;
    return ret;
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    const int m = 100;
    int n, k, p, ans;
    ans = 0;
    cin >> n;
    vector<int> v;
    shave(v, 100);
    k = v.size();
    vector<int> u(k, 0);

    rep2(i, 1, n + 1)
    {
        p = i;
        rep(j, k)
        {
            while (p % v[j] == 0)
            {
                u[j]++;
                p /= v[j];
            }
        }
    }

    ans = get756(u);
    cout << ans << endl;
    return 0;
}
