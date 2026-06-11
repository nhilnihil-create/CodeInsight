#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    long long int a,b,c,k,ans;
    double ans2;
    cin>>a>>b>>c>>k;
    if(k%2==1){
        ans2=b-a;
        ans=b-a;
    }else{
        ans2=a-b;
        ans=a-b;
    }
    if(abs(ans2)>1e+18)cout<<"Unfair"<<endl;
    else cout<<ans<<endl;
}
