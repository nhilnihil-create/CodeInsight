#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n;

int main()
{
    cin >> n;
    int cnt = 0;
    int l = 0, r = 0, lr = 0;
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(i, s.size() - 1)
        {
            if(s[i] == 'A' && s[i + 1] == 'B')
            {
                cnt++;
            }
        }
        if(*s.begin() == 'B' && *(s.end() - 1) == 'A')
        {
            lr++;
        }
        else if(*s.begin() == 'B')
        {
            l++;
        }
        else if(*(s.end() - 1) == 'A')
        {
            r++;
        }
    }
    
    //cout << res << " " << lr << " " << l << " " << r << endl;
    if(r == 0 && l == 0 && lr != 0)
    {
        cout << cnt + lr - 1 << endl;
    }
    else
    {
        cout << cnt + min(l, r) + lr << endl;
    }

    return 0;
}