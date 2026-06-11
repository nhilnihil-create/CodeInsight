#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,q;
    cin>>a>>b>>q;
    long long s[a],t[b],x[q];
    for(int i=0;i<a;i++)cin>>s[i];
    for(int i=0;i<b;i++)cin>>t[i];
    for(int i=0;i<q;i++)cin>>x[i];
    for(int i=0;i<q;i++){
        long long m=1000000000000000000;
        if(x[i]<s[a-1]){
            long long r_shrine=*upper_bound(s,s+a,x[i]);
            if(r_shrine<t[b-1])m=min(m,*upper_bound(t,t+b,r_shrine)-x[i]);
            if(r_shrine>t[0])m=min(m,2*r_shrine-*(upper_bound(t,t+b,r_shrine)-1)-x[i]);
        }
        if(x[i]>s[0]){
            long long l_shrine=*(upper_bound(s,s+a,x[i])-1);
            if(l_shrine<t[b-1])m=min(m,*upper_bound(t,t+b,l_shrine)+x[i]-2*l_shrine);
            if(l_shrine>t[0])m=min(m,x[i]-*(upper_bound(t,t+b,l_shrine)-1));
        }
        if(x[i]<t[b-1]){
            long long r_temple=*upper_bound(t,t+b,x[i]);
            if(r_temple<s[a-1])m=min(m,*upper_bound(s,s+a,r_temple)-x[i]);
            if(r_temple>s[0])m=min(m,2*r_temple-*(upper_bound(s,s+a,r_temple)-1)-x[i]);
        }
        if(x[i]>t[0]){
            long long l_temple=*(upper_bound(t,t+b,x[i])-1);
            if(l_temple<s[a-1])m=min(m,*upper_bound(s,s+a,l_temple)+x[i]-2*l_temple);
            if(l_temple>s[0])m=min(m,x[i]-*(upper_bound(s,s+a,l_temple)-1));
        }
        cout<<m<<endl;
    }
    return 0;
}