#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    int l=0, r=N;
    cout << l << endl;
    string s;
    cin >> s;
    if(s == "Vacant") return 0;
    while(r-l>0)
    {
        int mid = (r+l) / 2;
        cout << mid << endl;
        string t;
        cin >> t;
        if(t == "Vacant") break;
        if(mid%2==0)
        {
            if(s==t) l=mid;
            else r=mid;
        }
        else
        {
            if(s==t) r=mid;
            else l=mid;
        }
    }

    return 0;
}
