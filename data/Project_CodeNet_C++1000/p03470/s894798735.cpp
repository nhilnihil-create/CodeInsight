#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d.begin(),d.end());
    int base=0;
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        if (base !=d[i] )
        {
            ans++;
        }
        base = d[i];
    }
    cout << ans << endl;
}