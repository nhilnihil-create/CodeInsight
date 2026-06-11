#include <iostream>
#include <vector>
using namespace std;
int main(void){
    
    long int n,h,w,ans=0,i,ab[1000][2];
    cin>>n>>h>>w;
    
    for(i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>ab[i][j];
        }
    }
    
    for(i=0;i<n;i++){
        if(ab[i][0] >= h && ab[i][1] >= w)
            ans++;
    }
    cout<<ans;
}