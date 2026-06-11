#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j;
    int n; cin >> n;
    vector<int> d(n); for (i=0; i<n; i++) cin >> d.at(i);
    vector<int> different(1, d.at(0));
    
    int d_size = different.size();
    bool different_tf = true;
    for (i=0; i<n; i++)
    {
        d_size = different.size();
        different_tf = true;
        for (j=0; j<d_size; j++)
        {
            if (different.at(j) == d.at(i)) different_tf = false;
        }
        if (different_tf) different.push_back(d.at(i));
    }
    cout << different.size() << endl;
}