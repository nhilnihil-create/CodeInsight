#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)
    {
        int p;
        cin >> p;
        p--;
        a[p] = i;
    }
    int ans = 0, cnt = 1;
    a.push_back(-1); //rep(i,n+1) cout << a[i] << " "; cout << endl;
    rep(i,n)
    {
        if(a[i+1] > a[i]) cnt++;
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    cout << n - ans << endl;

    return 0;
}