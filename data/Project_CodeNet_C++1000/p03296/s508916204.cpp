#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,ans=0,c=1,b;
    cin>>n;
    vector<int>a(n);
    cin>>a[0];
    b=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]==b){c++;}
        else if(a[i]!=b){ans+=c/2;c=1;b=a[i];}
        
    }
    ans+=c/2;
    cout<<ans;
}