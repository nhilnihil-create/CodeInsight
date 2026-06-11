#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    string S;
    cin >> S;
    string ans;
    if (S.size() != 26)
    {
        set<char> setC;
        REP(i, S.size())
        {
            setC.insert(S[i]);
        }
        for (char c = 'a'; c <= 'z'; ++c)
        {
            if (setC.find(c) == setC.end())
            {
                ans = S;
                ans.push_back(c);
                break;
            }
        }
    }
    else
    {
        bool flag = false;
        set<char> setC;
        REP(i, 26)
        {   
            setC.insert(S[25 - i]);
            REPV(it, setC)
            {
                char c = *it;
                if (c > S[25 - i])
                {
                    ans = S.substr(0, 25 - i);
                    ans.push_back(c);
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (!flag)
        {
            ans = "-1";
        }
    }

    cout << ans << endl;
}
