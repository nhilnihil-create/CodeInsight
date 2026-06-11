#include<bits/stdc++.h>

using namespace std;
#define taskname "A"
#define pb  push_back
#define mp  make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
const int maxn = 2005;
const int maxm = 1e4 + 5;
int a[maxn];
int n , k , q;
int res = 2e9;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin);
        freopen(taskname".OUT", "w",stdout);
    }
    cin >> n >> k >> q;
    for(int i = 1 ; i <= n ; ++i)cin >> a[i];
    for(int i = 1 ; i <= n ; ++i){
        vector<int> can , tmp;
        int now = a[i];
        for(int j = 1 ; j <= n + 1 ; ++j){
            if(now > a[j] || j == n + 1){
                sort(tmp.begin(),tmp.end());
                for(int c = 0 ; c + k - 1 < (int)tmp.size() ; ++c){
                    can.pb(tmp[c]);
                }
                tmp.clear();
            }else{
                tmp.pb(a[j]);
            }
        }
        sort(can.begin(),can.end());
//        if(can.size() >= q)cout << now << " " << can.size() << endl;
        if(can.size() >= q)res = min(res , can[q - 1] - now);
    }
    cout << res;
}
