#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 2e5 + 5;

int n;
int a[maxn] , b[maxn];
int c[maxn] , d[maxn];

int main(){
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        cin >> b[i];
    }
    auto Solve = [&](int t){
        for(int i = 1 ; i <= n ; ++i){
            c[i] = a[i] % (t * 2);
            d[i] = b[i] % (t * 2);
        }
        sort(d + 1 , d + n + 1);
        ll res = 0;
        for(int i = 1 ; i <= n ; ++i){
            res += lower_bound(d + 1 , d + n + 1 , 2 * t - c[i]) -
             lower_bound(d + 1 , d + n + 1 , t - c[i]);
            res += lower_bound(d + 1 , d + n + 1 , 4 * t - c[i]) -
             lower_bound(d + 1 , d + n + 1 , 3 * t - c[i]);
        }
        return res & 1;
    };
    int res = 0;
    for(int i = 0 ; i < 29 ; ++i){
        if(Solve(1 << i))res += (1 << i);
    }
    cout << res;
}

