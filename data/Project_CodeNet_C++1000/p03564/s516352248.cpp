#include <iostream>
using namespace std;

int main(){
    int n,k,ans=1,tmp_a,tmp_b;
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        tmp_a=2*ans;
        tmp_b=ans+k;
        
        if(tmp_a<tmp_b)
            ans=tmp_a;
        else
            ans=tmp_b;
            
    }
    cout<<ans<<endl;
}
