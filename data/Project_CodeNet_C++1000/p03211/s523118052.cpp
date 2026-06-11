#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,mn=1000,p=0,dif=0;
    string a;
    cin>>a;
    for(i=0; i+2<a.size(); i++)
    {
        p=0;
        dif=0;
        p=p*10+(a[i]-'0');
        p=p*10+(a[i+1]-'0');
        p=p*10+(a[i+2]-'0');
        dif=abs(p-753);
        mn=min(mn,dif);
    }
        cout<<mn<<endl;




}
