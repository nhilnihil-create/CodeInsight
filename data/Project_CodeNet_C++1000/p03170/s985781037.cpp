
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int maxN = 1e5+5;
const int mod = 1e9+7;
int arr[maxN];
bool dp[maxN];
int n,k;


void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<k+1;i++){
        for(int j=0;j<n;j++){
            if(i-arr[j]>=0){
                if(dp[i-arr[j]]==false){
                    dp[i] = true;
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    if(dp[k]==true)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}

int main()
{
    FASTIO
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




