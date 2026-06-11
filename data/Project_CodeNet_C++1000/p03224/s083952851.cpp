#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);
//ios::sync_with_stdio(false);

void solve(int x,int nofs)
{
    cout << nofs << endl;

    cout<<nofs-1<<" ";
    ll cnt=1;
    for(int i=1;i <= x;i+=cnt)
    {
        cout<<i<<" ";
        cnt++;
    }
    cout<<endl;

    cnt=0;
    for(int i=1;i <= x;i+=cnt)
    {
        cout<<nofs-1<<" ";
        ll cnt2=1;
        bool f=true;
        for(int j=i;j <=x ;j+=cnt2)
        {
            cout<<j<<" ";
            if(f && j==i+cnt){
                f=false;
                cnt2=cnt+1;
            }else if(!f){
                cnt2++;
            } 
        }
        cout<<endl;
        cnt++;
    }
}

signed main()
{
    int n;
    cin >> n;
    for(int i=2;i < 2000;i++)
    {
        if(2*n==i*(i-1)){
            cout<<"Yes"<<endl;
            solve(n,i);
            return 0;
        }
    }
    cout<<"No"<<endl;

}
