#include<iostream>
using namespace std;
string s,t;
main()
{
    int n,f,l,m;cin>>n;f=0;l=n;
    cout<<0<<endl;
    cin>>s;
    if(s=="Vacant")return 0;
    while(t!="Vacant"){
        m=(f+l)/2;
        cout<<m<<endl;
        cin>>t;
        if(m%2^s==t)f=m;
        else l=m;
    }
}