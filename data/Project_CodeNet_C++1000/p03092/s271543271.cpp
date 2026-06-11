#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define taskname "A"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 5e3 + 5;
const int maxm = 1e7 + 5;

const int mod = 1e9 + 7;
int n , A , B;
int pos[maxn] , a[maxn];
int m = 0;
ll f[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP" , "r"))
        freopen(taskname".INP","r",stdin),
        freopen(taskname".OUT","w",stdout);
    cin >> n >> A >> B;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        pos[a[i]] = i;
    }
    memset(f,123,sizeof  f);
    f[1][0] = 0;
    ll res = 1e18;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j < i ; ++j){
            if(pos[i] > pos[j]){
                f[i + 1][j] = min(f[i + 1][j] , f[i][j] + B);
                f[i + 1][i] = min(f[i][j] , f[i + 1][i]);
            }else{
                f[i + 1][j] = min(f[i + 1][j] , f[i][j] + A);
            }
        }
    }
    cout << *min_element(f[n+1],f[n+1]+n+1);
}
