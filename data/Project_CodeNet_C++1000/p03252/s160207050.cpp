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

    string S, T;
    cin >> S >> T;

    vector<int> v[30];
    FILL0(v);


    rep(i, T.size())
    {
        v[T[i]-'a'].push_back(i);
    }

    rep(i, 30)
    {
        if(v[i].size()>1)
        {
            char c = S[v[i][0]];
            rep(j, v[i].size())
            {
                if(c != S[v[i][j]])
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    FILL0(v);

    rep(i, T.size())
    {
        v[S[i]-'a'].push_back(i);
    }

    rep(i, 30)
    {
        if(v[i].size()>1)
        {
            char c = T[v[i][0]];
            rep(j, v[i].size())
            {
                if(c != T[v[i][j]])
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }



    cout << "Yes" << endl;

    return 0;

}
