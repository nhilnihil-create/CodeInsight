#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define FILL0(x) memset(x,0,sizeof(x))
#define FILL1(x) memset(x,-1,sizeof(x))

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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll l, r;
    l = r = 0; //rは次に見る場所

    int zero = 0;
    if(s[0]=='0')
    {
        zero = 1;
    }

    ll ans = 0;
    while(r<n)
    {
        if(zero<=k)
        {
            chmax(ans, r-l+1);

            if(s[r]=='1' && s[r+1]=='0')
            {
                zero++;
            }

            r++;
        }
        else
        {
            if(s[l]=='0' && s[l+1]=='1')
            {
                zero--;
            }
            l++;
        }
    }

    cout << ans << endl;
 
 
    
    


    return 0;

}
