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

    int N, K;
    cin >> N >> K;


    string S;
    cin >> S;

    int l, r;
    l=r=0;
    int zero;

    if(S[0]=='0')
    {
        zero=1;
    }
    else
    {
        zero=0;
    }
    int ans=0;
    while(r<N)
    {
        if(zero<=K)
        {
            chmax(ans, r-l+1);
            if(S[r]=='1' && S[r+1]=='0')
            {
                zero++;
            }
            r++;
        }
        else
        {
            if(S[l]=='0' && S[l+1]=='1')
            {
                zero--;
            }
            l++;
        }
    }

    cout << ans << '\n';
    
 

 

    return 0;
}

