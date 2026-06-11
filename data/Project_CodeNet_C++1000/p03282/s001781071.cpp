#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
    ll i,x,p=0,k,j=0;
    string str;
    cin>>str;
    cin>>k;
    for(i=0;i<str.size();i++)
    {
        x=(str[i]-48);

        if(x==1){
            p++;
        }
        else{
                j=i;
            break;
        }
    }

    if(k<=p)
        cout<<1<<endl;
    else
        cout<<str[j]<<endl;
    return 0;
}
