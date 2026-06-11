// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "U - Grouping"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 2e5;
int mx[16][16];
ll pre[(1<<16)];
ll dp[(1<<16)];

int n;

ll cal(int x){
    if(dp[x]!=-1) return dp[x];
    if (__builtin_popcount(x)<=1) return dp[x] =  0;

    ll val = pre[x];
    int subs = x;
    int opps;
    while(1){
        subs = (subs-1)&x;
        if (subs<=0) break;

        val = max(val,cal(subs) + cal( x^subs ));
    }

    return dp[x] = val;
}
int main(){
    //fstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>mx[i][j];
    vector<int> id;
    ll tmp;
    int subs;
    for(int i = 0;i<(1<<n);i++){
        for(int j = 0;j<n;j++)
            if(i>>j&1) id.emplace_back( j );
        tmp = 0;
        for(int j = 0; j<id.size() ; j++){
            for(int k = j+1;k<id.size();k++)
                tmp+= mx[ id[j] ][ id[k] ];
        }
        pre[i] = tmp;
        id.clear();
    }

    ms(dp,-1);

    cout<<cal( (1<<n) -1 )<<endl;
}
