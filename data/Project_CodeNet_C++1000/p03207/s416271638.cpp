#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin>>p.at(i);
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    int ans=p.at(0)/2;
    for(int i=1;i<n;i++){
        ans+=p.at(i);
    }
    cout<<ans<<endl;
}