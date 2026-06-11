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

    int N, M;
    cin >> N >> M;

    vector<ll> town[N];

    map<ll, ll> my;
    map<ll, ll> mp;
    vector<P> order;

    rep(i, M)
    {
        ll pt, yt;
        cin >> pt  >> yt;
        pt--;
    
        my[yt]=i;
        mp[pt]=i;
        order.push_back(P(pt, yt));

        town[pt].push_back(yt);
    }

    rep(i, N)
    {
        sort(town[i].begin(), town[i].end());
    }

    rep(i ,M)
    {
        ll p, y;
        p = order[i].first;
        y = order[i].second;

        int index = lower_bound(town[p].begin(), town[p].end(), y)-town[p].begin();

        string num1 = to_string(p+1);
        string num2 = to_string(index+1);


        int size1 = 6-num1.size();
        int size2 = 6-num2.size();
        
        cout << string(size1,'0') + num1+string(size2,'0')+num2 << endl;

    }








    return 0;
}
