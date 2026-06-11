#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    long long int x,y,ans;
    cin>>x>>y;
    if(x%y==0)ans=-1;
    else{
        ans=x*y+x;
    }
    cout<<ans<<endl;
}