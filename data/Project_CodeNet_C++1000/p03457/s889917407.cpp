#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>t(n+1),x(n+1),y(n+1);
    bool flag=true;
    t[0]=0,x[0]=0,y[0]=0;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>x[i]>>y[i];
        if(t[i]-t[i-1]>=abs(x[i]-x[i-1])+abs(y[i]-y[i-1])){
            if((t[i]-t[i-1])%2!=0&&(abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))%2==0){flag=false;}
            else if((t[i]-t[i-1])%2==0&&(abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))%2!=0){flag=false;}
        }else{
            flag=false;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}