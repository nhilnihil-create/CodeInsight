#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,t,a;
    cin>>n>>t>>a;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }

    int r=1e9,ans=-1;
    for(int i=0;i<n;i++){
        int k=1000*t-6*h[i];
        if(abs(k-a*1000)<r){
            ans=i+1;
            r=abs(k-a*1000);
        }
    }
    cout<<ans<<endl;
}