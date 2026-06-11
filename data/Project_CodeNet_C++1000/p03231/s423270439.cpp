#include <iostream>
using namespace std;
int n,m;
char s[100000],t[100000];

int gcd(int x,int y){
    if(x>y){
        x+=y;
        y=x-y;
        x-=y;
    }if(x==0) return y;
    return gcd(y%x,x);
}

int main(){
    cin>>n>>m;
    int g=gcd(n,m);
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<m;i++)cin>>t[i];
    n/=g; m/=g;
    for(int i=0;i<g;i++){
        if(s[n*i]!=t[m*i]){
            cout<<-1;
            return 0;
        }
    }
    cout<<(long long)n*m*g;
    return 0;
}
