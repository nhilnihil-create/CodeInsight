#include <iostream>
using namespace std;

#define int long long
const int N = 2e5+5, INF = 1e18;
int n, a[N], pref[N], ans = INF;

int sum(int l, int r)
{
    return pref[r] - pref[l-1];
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    for (int i = 3; i <= n-1; i++)
    {
        //if (i != 5) continue;
        int pos1, pos2, ans1 = INF, ans2 = INF;

        int l = 1, r = i-1;
        while(l < r)
        {
            int mid = (l+r)/2;
            int tmp = 2*sum(1,mid) - sum(1,i-1);
            if (abs(tmp) < ans1)
            {
                ans1 = abs(tmp);
                pos1 = mid;
            }
            if (tmp < 0)
                l = mid+1;
            else
                r = mid;
        }
        l = i, r = n;
        while(l < r)
        {
            int mid = (l+r)/2;
            int tmp = 2*sum(i,mid) - sum(i,n);
            //cout << mid << ' ' << tmp << endl;
            if (abs(tmp) < ans2)
            {
                ans2 = abs(tmp);
                pos2 = mid;
            }
            if (tmp < 0)
                l = mid+1;
            else
                r = mid;
        }
        int sum1 = sum(1,pos1), sum2 = sum(pos1+1,i-1), sum3 = sum(i,pos2), sum4 = sum(pos2+1,n);
        //cout << pos1 << ' ' << i << ' ' << pos2 << endl;
        //cout << sum1 << ' ' << sum2 << ' ' << sum3 << ' ' << sum4 << endl;
        ans = min(ans,max(sum1,max(sum2,max(sum3,sum4))) - min(sum1,min(sum2,min(sum3,sum4))) );
    }
    cout << ans;
}
