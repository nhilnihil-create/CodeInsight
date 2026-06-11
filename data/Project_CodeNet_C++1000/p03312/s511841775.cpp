#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(i){
            s[i]+=s[i-1];
        }
    }
    int i=0,j=2;
    while(j<n-2){
        if(abs(s[j+1]-s[1]-(s[n-1]-s[j+1]))<abs(s[j]-s[1]-(s[n-1]-s[j]))){
            j++;            
        }
        else{
            break;
        }
    }
    // cout<<i<<" "<<j<<endl;
    long long ans=max(s[i],max(s[1]-s[i],max(s[j]-s[1],s[n-1]-s[j])))-min(s[i],min(s[1]-s[i],min(s[j]-s[1],s[n-1]-s[j])));
    for(int l=2;l<n-2;l++){
        while(i<l-1){
            if(abs(s[i]-(s[l]-s[i]))>abs(s[i+1]-(s[l]-s[i+1]))){
                i++;
            }
            else{
                break;
            }
        }
        while(j<n-2){
            if(abs(s[j]-s[l]-(s[n-1]-s[j]))>abs(s[j+1]-s[l]-(s[n-1]-s[j+1]))){
                j++;
            }
            else{
                break;
            }
        }
        ans=min(ans,max(s[i],max(s[l]-s[i],max(s[j]-s[l],s[n-1]-s[j])))-min(s[i],min(s[l]-s[i],min(s[j]-s[l],s[n-1]-s[j]))));
    }
    cout<<ans<<endl;
    return 0;
}