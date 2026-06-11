#include<bits/stdc++.h>
using namespace std;
int n,a,b,p;
multiset<int>s;
main(){
    cin>>n;
    while(n--)cin>>a,s.insert(a);
    while(s.size()){
        a=*s.rbegin();
        s.erase(s.find(a));
        p=1;
        while(p<=a)p*=2;
        if(s.find(p-a)!=s.end())s.erase(s.find(p-a)),b++;
    }
    cout<<b<<'\n';
}