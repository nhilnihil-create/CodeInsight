#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    cin>>a;
    int len=a.length(),i,sum=0;
    for(i=0;i<len;i++){
       if(a[i]=='0' && a[i]==a[i+1]){
        sum+=1;
        a[i+1]='1';
       }
       else if(a[i]=='1' && a[i]==a[i+1]){
        sum+=1;
        a[i+1]='0';
       }
    }
    cout<<sum;
    return 0;
}
