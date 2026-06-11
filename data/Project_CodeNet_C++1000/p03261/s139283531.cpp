#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(void)
{
    int n;
    cin >> n;
    vector<string> w(n);
    set<string> s;
    for (int i = 0;i < n;i++)
    {
        cin >> w[i];
        s.insert(w[i]);
    }
    bool ok = true;
    char back_ward;
    for (int i = 0;i < n-1;i++)
    {
        back_ward = w[i][w[i].size()-1];
        if (w[i+1][0] != back_ward) ok = false;
    }

    if (s.size() != w.size()) ok = false;

    cout << (ok? "Yes":"No") << endl;
    
    return 0;
}
