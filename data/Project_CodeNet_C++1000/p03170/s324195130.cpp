// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "K - Stones"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 1e5;
int arr[maxn];
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    int n,k;
    cin>>n>>k;

    for(int i = 0 ;i<n;i++) cin>>arr[i];

    vector <bool> dp(k+1);
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++)
            if(i>=arr[j] && !dp[i-arr[j]]) dp[i] = 1;
    }
    
    if(dp[k])
        cout<<"First\n";
    else
        cout<<"Second\n";
}
