#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    vector<int> rlen;
    vector<char> state;
    char cur = ' ';
    int idx = -1;
    for(int i = 0; i < n; ++i)
    {
        if(cur != str[i])
        {
            rlen.push_back(0);
            cur = str[i];
            state.push_back(str[i]);
            idx += 1;
        }
        rlen[idx] += 1;
    }

    for(int i = 1; i < (int)rlen.size(); ++i)
    {
        rlen[i] += rlen[i-1];
    }
    vector<int> ans(rlen.size());
    for(int i = 0; i < (int)rlen.size(); ++i)
    {
        int t = 0;
        if(state[i] == '0')
        {
            t = min(idx,i+(2*k-1));
        }
        else
        {
            t = min(idx,i+2*k);
        }
        ans[i] = rlen[t];
        if(i != 0)
        {
            ans[i] -= rlen[i-1];
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
}