#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


bool k_flip(string s, int k)
{
    int n = s.length();

    int status = 0;
    deque<int> endindex;

    rep(i, n - k + 1)
    {
        if (endindex.size() % 2 == 0 && s[i] == '1')
        {
            s[i] = '0';
            endindex.push_back(i + k - 1);
        }
        else if (endindex.size() % 2 == 1 && s[i] == '1')
        {
            s[i] = '0';
        }
        else if (endindex.size() % 2 == 1 && s[i] == '0')
        {
            endindex.push_back(i + k - 1);
        }

        if (endindex.front() == i)
            endindex.pop_front();
    }

    rep2(i, n - k + 1, n)
    {
        if (endindex.size() % 2 == 1)
        {
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }

        if (endindex.front() == i)
            endindex.pop_front();
    }

    rep(i, k)
        if (s[i] == '1')
            status++;

    if (!status)
        return 1;
    else
        return 0;
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    string s;
    cin >> s;
    int ok, ng, mid;

    if (k_flip(s, s.length()))
        cout << s.length() << endl;
    else
    {
        ok = 0, ng = s.length();
        while (ng - ok> 1)
        {
            mid = (ok + ng) / 2;
            if (k_flip(s, mid))
                ok = mid;
            else
                ng = mid;
            
        }
        cout << ok << endl;
    }

    return 0;
}