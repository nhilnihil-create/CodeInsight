#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define pb push_back
#define MOD 1000000007
#define sz5 100005
#define sz6 1000005
#define UP upper_bound
#define LB lower_bound
#define F first
#define S second
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>


int main() {
    FAST

    // #ifndef ONLINE_JUDGE
    //     freopen("in", "r", stdin);
    //     // freopen("out", "w", stdout);
    // #endif

    int n,k,la,lb;
    cin>>n>>k;
    
    bool mk[k+5]={0};
    mk[0]=false;
    int arr[n+5];
    
    for(la=1;la<=n;la++)
        cin>>arr[la];

    for(la=1;la<=n;la++)
        mk[arr[la]]=true;

    for(la=1;la<=k;la++){
        if(mk[la])
            continue;
        bool cur=true;
        for(lb=1;lb<=n;lb++)
        if(arr[lb]<=la)
            cur=min(cur, mk[la-arr[lb]]);
        
        if(!cur)
            mk[la]=true;
        else
            mk[la]=false;
    }

    if(mk[k])
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    return 0;
}