#include<bits/stdc++.h>
using namespace std;
int n,a,b,last;
void work(int len){
    int l=last+1,r=last+len;
    for (int i=r;i>=l;i--)
        cout<<i<<' ';
    last+=len;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    if (a+b>n+1||(long long)a*b<n){
        cout<<-1;
        return 0;
    }
    int len=0,c=0;
    if (a>1)len=(n-b)/(a-1),c=(n-b)%(a-1);
    for (int i=1;i<=c;i++)
        work(len+1);
    for (int i=c+1;i<a;i++)
        work(len);
    work(b);
    return 0;
}