#include <bits/stdc++.h>
using namespace std;

int  main() {
string s;
int n,q;
cin>>n>>q;
cin>>s;

int arr[n+1]={0};
int length=0;
for(int i=1;i<n;i++)
{
    if(s[i]=='C'&&s[i-1]=='A')
    arr[i]=1;
    arr[i]+=arr[i-1];

}

int l,r;
while(q--)
{
    cin>>l>>r;
    cout<<arr[r-1]-arr[l-1]<<endl;
}
return 0;
}
