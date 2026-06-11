#include<bits/stdc++.h>
using namespace std;
int sum[3];
int main()
{

    char str[100000+10];
    cin>>str;
    for(int i=0;i<strlen(str);++i)
    {
        if(str[i]=='a') sum[0]++;
        if(str[i]=='b') sum[1]++;
        if(str[i]=='c') sum[2]++;
    }
    sort(sum,sum+3);
    //cout<<sum[2]<<sum[1]<<sum[0]<<endl;
    if(2*sum[2]-sum[1]-sum[0]>2) cout<<"NO"<<endl;
    else cout<<"YES\n";
    return 0;
}
