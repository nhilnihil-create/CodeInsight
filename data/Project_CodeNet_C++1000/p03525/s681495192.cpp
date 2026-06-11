#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 50;
const int INF = 2e9;
const double PI = acos(-1);

int arr[N+10], cnt[30];

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(cnt,0,sizeof(cnt));
    bool flag = 1;

    int n;
    sf("%d",&n);
    if(n > 24) flag = 0;

    arr[0] = 0;
    for(int i=1;i<=n;++i){
        sf("%d",&arr[i]);
        cnt[arr[i]] += 1;
        if(cnt[arr[i]] == 3) flag = 0;
        if(!flag) break;
    }

    if(!flag){
        pf("0\n");
        return 0;
    }

    sort(arr,arr+n+1);

    for(int i=1;i<=n;++i){
        if(i%2 == 1){
            arr[i] = 24-arr[i];
        }
    }
    sort(arr,arr+n+1);

    int minn = INF;
    for(int i=1;i<=n;++i){
        minn = min(minn, arr[i]-arr[i-1]);
    }

    minn = min(minn, 24-arr[n]);
    if(minn == 24) minn = 0;
    pf("%d\n",minn);

    return 0;
}