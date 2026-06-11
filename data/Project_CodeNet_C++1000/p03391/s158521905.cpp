#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 5e5 + 5;
multiset<int,greater<int>> s[maxn];
int n , a[maxn];

int main(){
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    int n;cin >> n;
    ll resl = 0 , resr = 0;
    bool dif = 0;
    int res = 1e9;
    for(int i = 1 ; i <= n ; ++i){
        int x , y;cin >> x >> y;
        if(x > y)res = min(res , y);
        resl += x;
        dif |= (x != y);
    }
    if(dif)cout << resl - res;
    else cout << 0;
}

