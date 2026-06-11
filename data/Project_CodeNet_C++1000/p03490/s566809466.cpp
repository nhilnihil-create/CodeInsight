#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> x(2);
vector<vector<int> > vec(2);

int main()
{
    cin >> s;
    cin >> x[0] >> x[1];
    int mode = 0;
    int len = 0;
    vec[1].push_back(0);
    for (auto c : s)
    {
        if (c == 'F')
        {
            len++;
        }
        else
        {
            vec[mode].push_back(len);
            len = 0;
            mode = 1 - mode;
        }
    }
    vec[mode].push_back(len);
    
    for (int dim=0; dim<2; dim++)
    {
        vector<bool> dp_now(32001, false);
        dp_now[16000] = true;
        for (int i=0; i<vec[dim].size(); i++)
        {
            vector<bool> dp_next = vector<bool>(32001, false);
            if (i==0) dp_next[16000+vec[dim][0]] = true;
            else
            {
                for (int j=8000; j<=24000; j++)
                {
                    if (dp_now[j-vec[dim][i]] || dp_now[j+vec[dim][i]]) dp_next[j] = true;
                }
            }
            dp_now = dp_next;
        }
        if (!dp_now[16000+x[dim]])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}