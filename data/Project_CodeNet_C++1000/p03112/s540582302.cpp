#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int A,B,Q;
    cin>>A>>B>>Q;
    long long s[A+2],t[B+2],x;
    s[0]=t[0]=-20000000001;s[A+1]=t[B+1]=20000000001;
    for(int i=1;i<=A;i++)cin>>s[i];
    for(int i=1;i<=B;i++)cin>>t[i];
    for(int i=1;i<=Q;i++){
        cin>>x;
        int s2=lower_bound(s,s+A+2,x)-s,t2=lower_bound(t,t+B+2,x)-t;
        cout<<min({ x-min(s[s2-1],t[t2-1]),s[s2]-t[t2-1]+min(s[s2]-x,x-t[t2-1]),t[t2]-s[s2-1]+min(t[t2]-x,x-s[s2-1]),max(s[s2],t[t2])-x})<<endl;
    }
    return 0;
}