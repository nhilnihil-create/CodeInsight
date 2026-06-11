#include<bits/stdc++.h>
using namespace std;
int n,k;

string solve(vector<int> a){
    sort(a.begin(), a.end());
    vector<int> dp(k+1,0);
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-a[j]<0)
                break;
            if(dp[i-a[j]]==0){
                dp[i] =1;
                break;
            }
        }
    }
    if(dp[k]==0)
        return "Second";
    return "First";
}

int main(){

    cin>>n>>k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(a)<<endl;
    return 0;
}
