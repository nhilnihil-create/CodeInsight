#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,i,n;
    char ch[1000];
    cin>>ch>>n;
    l=strlen(ch);
    for(i=0;i<l;i=i+n) cout<<ch[i];
    cout<<endl;
    return 0;
}
