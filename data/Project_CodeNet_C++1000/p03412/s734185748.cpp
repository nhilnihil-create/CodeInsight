#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define mid (low+high)/2
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e9+7

using namespace std;

ll n,a[N],b[N];
ll s[N],t[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    rep(i,0,n)
        cin >> a[i];

    rep(i,0,n)
        cin >> b[i];

    ll num = 1;
    ll ans = 0;

    rep(bit,0,29)
    {
        ll mod = num*2;

        rep(i,0,n)
            s[i] = a[i]%mod;
        rep(i,0,n)
            t[i] = b[i]%mod;

        sort(s,s+n);
        reverse(s,s+n);
        sort(t,t+n);

        ll low = 0;
        ll high = 0;
        ll last = 0;
        ll cnt = 0;

      //  cout << bit << ":\n";

        rep(i,0,n)
        {
         //   cout << s[i] << " " << t[i] << endl;
            while(high < n && s[i]+t[high] < mod) // high = first index s.t. s[i]+t[high] >= 2*num
                high++;

            while(low < n && s[i]+t[low] < num) // low = first index s.t. s[i]+t[low] >= num
                low++;

            while(last < n && s[i]+t[last] < 3*num)
                last++;

            cnt += high-low;
            cnt += n-last;

            //cout << i << " " << low << " " << high << "  " << last << endl;
        }

        if(cnt%2==1)
            ans += num;

        num *= 2;
    }

    cout << ans;

    return 0;
}
