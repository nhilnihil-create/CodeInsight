#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];

    long long suma = 0, sumb = 0;
    for (int i = 0; i < n; i++)
    {
        suma += a[i];sumb += b[i];
        
    }

    if(suma > sumb)
    {
        cout << "No" << endl;
    }
    else
    {
        string ans = "Yes";
        long long ca = 0, cb = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i] > b[i])cb += a[i] - b[i];
            else if(a[i] < b[i])
            {
                if((b[i] - a[i]) % 2 == 0)ca += (b[i] - a[i]) / 2;
                else
                {
                    ca += (b[i] - a[i]) / 2 + 1;
                    cb ++;
                }
            }
        }
        //cout << ca  << " " << cb << " " << sumb - suma << endl;
        if(max(cb, ca) > sumb - suma)ans = "No";
        cout << ans << endl;
    }
    
}