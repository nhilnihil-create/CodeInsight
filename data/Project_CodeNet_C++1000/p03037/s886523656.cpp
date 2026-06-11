#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    long long n,m,l1,r1,l=0,r=100000;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>l1>>r1;

        if(l1>l){
            l=l1;
        }
        if(r>r1){
            r=r1;
        }
    }
    cout<<max(r-l+1,0LL)<<endl;
    return(0);
}