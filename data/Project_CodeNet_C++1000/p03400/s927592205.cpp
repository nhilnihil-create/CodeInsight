#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,x;
    cin>>n>>d>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a.at(i);
    }
    int ans=0;
   for(int i=0; i<n; i++){
       ans+=1+(d-1)/a.at(i);
   }
    ans+=x;
    cout<<ans<<endl;
}