#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, g, I;
    cin >> n;
    long long S[n], M=5000000000, p, k, L=0, R=200002, t;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    while (R - L > 1)
    {
        t = (L + R) / 2;
        g = 1;
        set <long long> Se;
        set <long long> :: iterator it;
        unordered_map <long long, long long> Ma;
        for (int i = 1; i < n; i++)
        {
            it = Se.lower_bound(M-2000000000);
            while (it != Se.end() && M-(*it) >= S[i])
            {
                Ma[M-*it] = 0;
                Se.erase(it);
                it = Se.lower_bound(M-200000000);
            }
            if (S[i] <= S[i-1])
            {
                if (t == 1)
                {
                    g = 0;
                    break;
                }
                I = S[i]-1;
                while (I >= 0 && Ma[I] == t-1)
                {
                    Se.erase(Se.find(M-I));
                    Ma[I] = 0;
                    I--;
                }
                if (I < 0)
                {
                    g = 0;
                    break;
                }
                if (Ma[I] == 0)
                {
                    Se.insert(M-I);
                }
                Ma[I]++;
            }
        }
        if (g == 1)
        {
            R = t;
        }
        else
        {
            L = t;
        }
    }
    cout << R;
    return 0;
}
