#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,t,c,t1;
    cin>>n>>t;
    int ans=2000;
    for(int i=0;i<n;i++){
        cin>>c>>t1;
        if(t1<=t){        
            if(c<ans){
                ans=c;
            }
        }
    }
    if(ans==2000)cout<<"TLE"<<endl;
    else cout<<ans<<endl;
    return 0;
}