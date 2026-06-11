#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    int n,t[102],v[102],m=0;
    double w[50000],z=0;
    cin>>n;
    t[0]=0;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        t[i]+=t[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    m=t[n]*2;
    int a=1;
    w[0]=0;
    for(int i=1;i<=m;i++){
        while((i+1)/2>t[a]){
            a++;
        }
        w[i]=min((double)w[i-1]+0.5, (double)v[a]);
    }
    a=n;
    w[m]=0;
    for(int i=m-1;i>=0;i--){
        while(i/2<t[a-1]){
            a--;
        }
        w[i]=min((double)w[i+1]+0.5, min(w[i],(double)v[a]));
    }
    //cout<<setprecision(20)<<z<<endl;
    for(int i=1;i<=m;i++){
        z+=(w[i]+w[i-1])/4;
        //cout<<"---"<<i<<":"<<w[i]<<endl;
    }

    cout<<setprecision(20)<<z<<endl;

}
