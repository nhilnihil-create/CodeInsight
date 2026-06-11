#include <bits/stdc++.h>
 
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
 
    int N;
    cin >> N;
    int t=N;
 
    vector<ll> x, y, h;
    
    ll tx, ty, th;

    rep(i, t)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if(c!=0)
        {
            tx=a;
            ty=b;
            th=c;
        }
        x.push_back(a);
        y.push_back(b);
        h.push_back(c);
    }
 
    rep(cx, 101)
    {
        rep(cy, 101)
        {

            ll H = th+abs(cx-tx)+abs(cy-ty);
            rep(i, x.size())
            {
                if(H == h[i]+abs(cx-x[i])+abs(cy-y[i]) ||  (h[i]==0&&H<=abs(cx-x[i])+abs(cy-y[i])))
                {
                    
                }
                else
                {
                    break;
                }
                
 
                if(i==x.size()-1)
                {
                    cout << cx  << " " << cy << " " << H << endl;
                    return 0; 
                }
            }
        }
    }
 
 
    return 0;
}