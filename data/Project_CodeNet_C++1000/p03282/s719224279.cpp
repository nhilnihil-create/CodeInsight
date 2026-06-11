#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    string str;
    int k;
    cin>>str>>k;
    for(int i=0;i<min((long long)str.size(),k);i++)
    {
        if(str[i]>='2'){cout<<str[i]<<endl;
        return 0;}
    }
    cout<<"1"<<endl;
}
