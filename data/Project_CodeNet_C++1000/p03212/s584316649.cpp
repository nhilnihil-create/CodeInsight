#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    queue<string> q;
    vector<string> numV;
    numV.push_back("3");
    numV.push_back("5");
    numV.push_back("7");
    q.push("357");
    q.push("375");
    q.push("537");
    q.push("573");
    q.push("735");
    q.push("753");
    ll ans = 0;
    map<string, bool> countMap;
    while(!q.empty())
    {
        string s = q.front();
        ll p = stoll(s);
        q.pop();
        if (p <= N) 
        {
            ans++;
            REPV(it, numV)
            {
                REP(i, s.size() + 1)
                {
                    string pushS;
                    if (i == 0)
                    {
                        pushS = *it + s;
                    }
                    else if (i == s.size())
                    {
                        pushS = s + *it;
                    }
                    else
                    {
                        pushS = s.substr(0, i) + *it + s.substr(i, s.size() - 1);
                    }
                    if (countMap.find(pushS) == countMap.end())
                    {
                        countMap[pushS] = true;
                        q.push(pushS);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
