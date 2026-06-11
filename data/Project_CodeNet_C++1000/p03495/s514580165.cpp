#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(200001,0);
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        ++a[temp];
    }
    
    sort(a.begin(),a.end(),greater<int>());
    int ans=0;
    for(int i=k;i<n;++i){
        if(a[i]!=0) ans+=a[i];
        else break;
    }

    cout<<ans<<endl;
}