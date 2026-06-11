#include <bits/stdc++.h>
using namespace std;
int N;
int m[1111111];
int s(int x){
    int r=0;
    while(x){r+=x%10;x/=10;}
    return r;
}
int f(int x){
    if(m[x]==0){
        int r=m[x]=1e9;
        int sx=s(x);
        if(x<N){
            for(int i=0;i<10;i++)r=min(r,f(x*10+i));
        }
        else if(x%N==0)r=sx;
        else{
            r=min(r,sx-s(x%N)+f(x%N));
        }
        m[x]=r;
    }
    return m[x];
}
int main(){
    cin>>N;
    while(N%2==0)N/=2;
    while(N%5==0)N/=5;
    cout<<f(0);
    return 0;
}
