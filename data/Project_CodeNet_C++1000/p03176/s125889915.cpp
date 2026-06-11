#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define lcm(x, y) ((x) * (y) / __gcd((x), (y)))
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define part cout << "----------------------------------\n";
#define fastinput                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<LL> t;
vector<LL> v, a, h;

void update_value(LL v, LL tl, LL tr, LL pos, LL val)
{
   // debug(v);
    if (tl == tr)
    {
        t[v] = val;
    }
    else
    {
        LL tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update_value(2 * v, tl, tm, pos, val);
        }
        else
        {
            update_value(2 * v + 1, tm + 1, tr, pos, val);
        }
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

LL query(LL v, LL tl, LL tr, LL left, LL right)
{
   // debug(v);
    
    if (right < left)
    {
        return -100000000000;
    }
    else if (tl == left && tr == right)
    {
        return t[v];
    }
    else
    {
        LL tm = (tl + tr) / 2;
        LL a1 = query(2 * v, tl, tm, left, min(right, tm));
        LL a2 = query(2 * v + 1, tm + 1, tr, max(tm + 1, left), right);
        return max(a1, a2);
    }
}

int main()
{
    fastinput;
    LL n, i, j, k,  temp;
    cin >> n;

    v.resize(n);
    a.resize(n);
    h.resize(n);

    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<LL> s(all(h));
    v.assign(all(s));
    LL sz = v.size();
    LL ans=-1;
    t.assign(4 * sz + 1,0);
    
    for(i=0;i<n;i++)
    {
        LL pos=lower_bound(all(v),h[i])-v.begin();
        LL maxima=query(1,0,sz-1,0,pos-1);
        LL prev=max(maxima,0LL);
        update_value(1,0,sz-1,pos,prev+a[i]);
        ans=max(ans,prev+a[i]);
       // debug(i);
       // debug(pos);
       // debug(maxima);
       // debug(prev);
       // part;
        //return 0;

    }
    cout<<ans<<endl;

    return 0;
}
