#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,a[3005],ans=0,m;
    string s[105],t[105];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(s[i]==s[j]){
                sum++;
            }
        }
        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                sum--;
            }
        }
        if(sum>ans){
            ans=sum;
        }
    }
    cout<<ans<<endl;
    return(0); 
}
