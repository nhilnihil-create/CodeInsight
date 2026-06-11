#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define taskname "A"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 5000 + 5;
const int logn = log2(maxn) + 1;
const int inf = 1e9 + 1;
int L;
vector<pair<ii,int>> E;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP" , "r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    cin >> L;--L;
    E.pb(mp(mp(0,19),L));
    for(int i = 0 ; i <= 18 ; ++i){
        E.pb(mp(mp(i,i+1),0));
    }
    for(int i = 0 ; (1 << (i + 1)) <= L ; ++i){
        E.pb(mp(mp(i,i+1),(1<<i)));
    }
    int pre = 0;
    for(int i = 19 ; i >= 0 ; --i){
        if(L & (1 << i)){
            if(pre)E.pb(mp(mp(i,19),pre));
            pre |= (1 << i);
//            cout << i << endl;
        }
    }
    cout << 20 << " " << E.size() << endl;
    for(auto c : E){
        cout << c.first.first + 1 << " " << c.first.second + 1 << " " << c.second << '\n';
    }
}