#include <bits/stdc++.h>

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll A, B;
    cin >> A >> B;

    ll BA = B-A+1;

    bool flag = false;
    bool pflag =false;
    if(A%2==1)
    {
        pflag=true;
        BA--;
    }

    if(BA%2==1)
    {
        BA--;
        flag=true;
    }
    ll ans = 0;
    if(BA%4!=0)
    {
        ans=1;
    }

    if(pflag)
    {
        ans^=A;
    }

    if(flag)
    {
        ans ^=  B;
    }

    cout << ans << endl;
    

    

 

 

    return 0;
}

