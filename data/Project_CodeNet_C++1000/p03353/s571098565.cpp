#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    string s;
    int k;
    cin >> s >> k;
    set<string> st;
    for(int i = 0;i < s.size();i++)
    {
        for(int j = 1;j <= k;j++)
        {
            st.insert(s.substr(i,j));
        }
    }
    auto itr = st.begin();
    for(int i = 0;i < k - 1;i++)
    {
        itr++;
    }
    cout << *itr << "\n";

    return 0;
}