#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    long long int ans=1,def=1;
    int n;
    cin>>n;
    int x;
    for(i=0;i<n;i++){
        cin>>x;
        ans*=3;
        if(x%2==0){
            def*=2;
        }else{
            def*=1;
        }
    }
    cout<<ans-def<<endl;
}
