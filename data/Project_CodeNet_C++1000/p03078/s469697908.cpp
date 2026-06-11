#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
const int N = 1e3+5;

ll n , x , y , z , k , a[N] , b[N] , c[N];
vector<ll> v;
priority_queue<ll> q;

bool check(ll num)
{
    ll cnt = 0 , up , rem;
    for(int i=1; i<=x; i++)
    {
        rem = num - a[i]; //m7tag kam 3shan ab2a num
        up = upper_bound(v.begin() , v.end() , rem-1) - v.begin(); //3dd el as8ar
        up = v.size() - up;
        cnt += up;
    }

    return cnt >= k;
}

void solve(ll val)
{
    for(int i=1; i<=x; i++)
    {
        int j=(int)v.size()-1;
        while(j>=0 && k>=0 && a[i]+v[j] > val)
        {
            k--;
            q.push(a[i]+v[j]);
            j--;
        }
    }
    while(k>0) q.push(val) , k--;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> x >> y >> z >> k;
    for(int i=1; i<=x; i++)
    {
        cin >> a[i];
    }

    sort(a+1 , a+x+1);
    for(int i=1; i<=y; i++)
        cin >> b[i];
    for(int i=1; i<=z; i++)
        cin >> c[i];

    for(int i=1; i<=y; i++)
    {
        for(int j=1; j<=z; j++)
        {
            v.push_back( (b[i]+c[j]) );
        }
    }

    sort(v.begin() , v.end());

    ll l = 1 , h = 1e14 , mid , idx = -1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if (check(mid))
        {
            idx = max(idx , mid);
            l = mid+1;
        }
        else h=mid-1;
    }

    solve(idx);

    while(q.size())
    {
        cout << q.top() << "\n";
        q.pop();
    }

    return 0;
}