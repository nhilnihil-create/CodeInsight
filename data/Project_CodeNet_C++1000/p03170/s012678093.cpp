#include <bits/stdc++.h>
using namespace std;
int minval=INT_MAX;
bool res(vector <int> &,int ,bool );
int main() {
    int n,k;
    cin>>n>>k;
    vector <int> arr(n);
    vector <bool> dp(k+1,false);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        minval=min(minval,arr[i]);
    }
    dp[minval]=1;
    for(int i=0;i<k+1;i++){
        for(int j=0;j<n;j++){
            if(i>=arr[j])
                dp[i]=dp[i]||(!dp[i-arr[j]]);
            if(dp[i]==true){
                break;
            }
        }
    }
    /*
    for(int i=0;i<k+1;i++){
        for(int j=0;j<n;j++){
            dp[i+arr[j]]=dp[i+arr[j]]||(!dp[i]);
        }
    }
     */
    if(dp[k]==true)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    /*
    if(res(arr,k,0))
        cout<<"second"<<endl;
    else
        cout<<"first"<<endl;
     */
}
bool res(vector <int> &arr,int weight,bool q){
    if(weight<minval)
        return !q;
    if(weight==minval)
        return q;
    for(int i=0;i<arr.size();i++){
        if(res(arr,weight-arr[i],!q)==q)
            return q;
    }
    return !q;
}