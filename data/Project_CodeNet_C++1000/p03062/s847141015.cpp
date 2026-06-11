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
    vector<ll> A(N);

    rep(i, N)
    {
        cin >> A[i];
    }

    ll cnt=0;
    ll zero=0;
    ll sum = 0;
    ll min=1e10;
    rep(i, N)
    {
        sum+=abs(A[i]);
        if(abs(A[i])<min)
        {
            min=abs(A[i]);
        }
        if(A[i]<0)
        {
            cnt++;
        }
    }

    

    if(cnt%2==0)
    {
        cout << sum << endl;
    }
    else
    {
        cout << sum-min*2 << endl;
    }
    


    

    return 0;
}

