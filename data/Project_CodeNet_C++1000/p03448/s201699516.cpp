#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    int ans=0;
    int num1=min(x/500,a);
    int num2=min(x/100,b);
    int num3=min(x/50,c);

    for(int h=num1;h>=0;h--){
        for(int i=num2;i>=0;i--){
            for(int j=num3;j>=0;j--){
                if(x==500*h+100*i+50*j) ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}