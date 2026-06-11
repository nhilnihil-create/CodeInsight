#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    vector<int> ns(4);
    for(int i=0; i<4; i++)
    {
        cin >> ns.at(i);
    }

    sort(ns.begin(), ns.end());

    if(ns.at(0) == 1 && ns.at(1) == 4 && ns.at(2) == 7 && ns.at(3) == 9)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    

    return 0;
}
