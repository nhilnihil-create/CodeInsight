#include <bits/stdc++.h>

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll counter = 0;
ll limit = 0;

void dfs(ll val, int cond)
{
    if(val > limit)
    {
        return ;
    }
    if( cond == 0b111) counter++;
    if(int(log10(val))==int(log10(limit)))
    {
        return;
    }

    dfs(val*10+3,cond|0b001);
    dfs(val*10+5,cond|0b010); 
    dfs(val*10+7,cond|0b100);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    limit=N;

    dfs(0,0);

    cout << counter << endl;

    return 0;
}

