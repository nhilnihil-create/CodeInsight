#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,q,d[100000],d2[100000],A,B,c,L,ans;
vector<ll> s,t;
int main(void){
    cin>>a>>b>>q;
    for(int i=0;i<a;i++){
        cin>>c;
        s.push_back(c);
    }
    for(int i=0;i<b;i++){
        cin>>c;
        t.push_back(c);
    }
    for(int i=0;i<s.size();i++){
        L=lower_bound(t.begin(),t.end(),s[i])-t.begin();
        A=abs(s[i]-t[L]);
        B=abs(t[max(0LL,L-1)]-s[i]);
        d[i]=min(A,B);
    }
    for(int i=0;i<t.size();i++){
        L=lower_bound(s.begin(),s.end(),t[i])-s.begin();
        A=abs(t[i]-s[L]);
        B=abs(s[max(0LL,L-1)]-t[i]);
        d2[i]=min(A,B);
    }
    while(q--){
        cin>>c;
        L=lower_bound(s.begin(),s.end(),c)-s.begin();
        A=abs(c-s[min((ll)s.size()-1,L)])+d[min((ll)s.size()-1,L)];
        B=abs(s[max(0LL,L-1)]-c)+d[max(0LL,L-1)];
        ans=min(A,B);
        L=lower_bound(t.begin(),t.end(),c)-t.begin();
        A=abs(c-t[min((ll)t.size()-1,L)])+d2[min((ll)t.size()-1,L)];
        B=abs(t[max(0LL,L-1)]-c)+d2[max(0LL,L-1)];
        ans=min(ans,min(A,B));
        cout<<ans<<endl;
    }
}
