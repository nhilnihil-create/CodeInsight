#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


const int mod = 1e9 + 7;

void solve(int n, int d[])
{
    int b, f[13], ans, ansi;
    vector<int> v, w, u;
    fill(f, f + 13, 0);
    ans = 0;


  
    rep(i, n) f[d[i]]++;

  
    if (f[0])
    {
        cout << 0 << endl;
        return;
    }
    if (f[12] >= 2)
    {
        cout << f[13] << endl;
        return;
    }
    if (*max_element(f, f + 13) >= 3)
    {
        cout << 0 << endl;
        return;
    }


  
    v.push_back(0);
    v.push_back(24);
    rep(i, 12)
    {
        if (f[i] == 2)
        {
            v.push_back(i);
            v.push_back(24 - i);
        }
        else if (f[i] == 1)
            w.push_back(i);
    }
    if (f[12])
        v.push_back(12);
    

    rep(i, pow(2, w.size()))
    {
        u = v;
        b = i;
        rep(j, w.size())
        {
            if (b % 2)
                u.push_back(w[j]);
            else
                u.push_back(24 - w[j]);
            b /= 2;
        }
        sort(u.begin(), u.end());


        ansi = 12;
        rep(j, u.size() - 1)
            ansi = min(ansi, u[j+1] - u[j]);
        ans = max(ans, ansi);
        u.clear();
        
    }
    cout << ans << endl;
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n;
    cin >> n;
    int d[n];
    rep(i, n) cin >> d[i];
    solve(n, d);

    return 0;
}
