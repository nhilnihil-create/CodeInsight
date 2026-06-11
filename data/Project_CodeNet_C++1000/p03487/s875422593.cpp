#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        m[a]++;
    }

    int ans=0;
    for(auto p : m){
        if(p.first<=p.second) ans+=p.second-p.first;
        else ans+=p.second;
    }
    cout<<ans<<endl;
}