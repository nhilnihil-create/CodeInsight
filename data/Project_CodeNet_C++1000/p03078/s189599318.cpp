#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
#include<tuple>

using namespace std;
typedef long long ll;

const ll MAX = 1000+1;
struct point
{
    ll p, i, j, k;
    point(ll p,ll i,ll j, ll k):p(p),i(i),j(j),k(k){}

    bool operator< (const point &rhs)const
    {
        return p < rhs.p;
    }
        
};



int main(){
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    for (ll i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < y; i++)
    {
        cin >> b[i];
    }
    for (ll i = 0; i < z; i++)
    {
        cin >> c[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
    priority_queue<point> pq;
    set<tuple<ll,ll,ll>> s;
    pq.push(point(a[0] + b[0] + c[0], 0, 0, 0));
    s.insert(make_tuple(0, 0, 0));
    for (ll l = 0; l < k; l++)
    {
        point p = pq.top();
        ll i = p.i;
        ll j = p.j;
        ll k = p.k;
        cout << p.p << endl;
        pq.pop();
        if(i+1<x &&s.find(make_tuple(i+1,j,k))==s.end())
        {
            pq.push(point(a[p.i + 1] + b[p.j] + c[p.k], p.i + 1, p.j, p.k));
            s.insert(make_tuple(i+1,j,k));
        }
        if(j+1<y&&s.find(make_tuple(i,j+1,k))==s.end())
        {
            pq.push(point(a[p.i] + b[p.j + 1] + c[p.k], p.i, p.j + 1, p.k));
            s.insert(make_tuple(i,j+1,k));
        }
        if(k+1<z&&s.find(make_tuple(i,j,k+1))==s.end())
        {
            pq.push(point(a[p.i] + b[p.j] + c[p.k + 1], p.i, p.j, p.k + 1));
            s.insert(make_tuple(i,j,k+1));
        }
    }
    return 0;
}