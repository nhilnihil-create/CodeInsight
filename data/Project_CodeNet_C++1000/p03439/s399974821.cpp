#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}


int main()
{
    int n;
    cin >> n;
    queue<int> q;
    q.push(n/2);
    string lefts,rights;
    cout << 0 << endl;
    cin >> lefts;
    if (lefts == "Vacant")
    {
        return 0;
    }
    cout << n-1 << endl;
    cin >> rights;
    if(rights=="Vacant"){
        return 0;
    }
    queue<int> hidari,migi;
    queue<string> hidas,migis;
    hidari.push(0);
    migi.push(n-1);
    hidas.push(lefts);
    migis.push(rights);
    while(!q.empty()){
        int left=hidari.front();
        int right=migi.front();
        hidari.pop();
        migi.pop();
        lefts=hidas.front();
        rights=migis.front();
        hidas.pop();migis.pop();
        cout << q.front() << endl;
        string s;
        cin >> s;
        if(s=="Vacant"){
            return 0;
        }
        else if(s=="Male"){
            if((q.front()-left)%2==(lefts=="Male")){
                q.push((q.front()+left)/2);
                migi.push(q.front());
                hidari.push(left);
                hidas.push(lefts);
                migis.push(s);
            }
            else if ((right-q.front()) % 2 == (rights == "Male"))
            {
                q.push((q.front()+right)/2);
                migi.push(right);
                hidari.push(q.front());
                hidas.push(s);
                migis.push(rights);
            }
        }
        else{
            if ((q.front() - left) % 2 == (lefts == "Female"))
            {
                q.push((q.front() + left) / 2);
                migi.push(q.front());
                hidari.push(left);
                hidas.push(lefts);
                migis.push(s);
            }
            else if ((right - q.front()) % 2 == (rights == "Female"))
            {
                q.push((q.front() + right) / 2);
                migi.push(right);
                hidari.push(q.front());
                hidas.push(s);
                migis.push(rights);
            }
        }
        q.pop();
    }
}
