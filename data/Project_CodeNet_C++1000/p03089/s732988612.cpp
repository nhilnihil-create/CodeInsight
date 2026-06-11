#include <bits/stdc++.h>

#define pan(i,n) for(int i=0;i<n;i++)
#define pans(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define INF 1000000007
#define PI 3.141592653
#define inf 100007
#define P pair<ll,ll>

using namespace std; 


int main(){
    int n;
    cin>>n;
    vi v(n),ans;
    pan(i,n) cin>>v[i];
    int i=0;
    while(i<n){
        // cout<<i<<endl;
        for(int j=v.size()-1;j>=0;j--){
            // cout<<j<<endl;
            // cout<<v.size()<<" ";
            if(v[j]==j+1){ 
                ans.pb(j+1);
                // cout<<j+1<<endl;
                v.erase(v.begin()+j);
                break;
            }
        }
        i++;
    }
    // cout<<ans.size()<<endl;
    if(ans.size()!=n) cout<<-1;
    else{
        for(i=n-1;i>=0;i--) cout<<ans[i]<<endl;
    }
}