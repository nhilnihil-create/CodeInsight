#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    int a,b,j,i,len;
    long long int c=0;
    cin>>a>>b;
   for(i=a;i<=b;i++){
        string str=to_string(i);
        len=str.length();
        bool flag=true;
        for(j=0;j<len/2;j++){
                if(str[j]!=str[len-j-1]){
                    flag=false;
                    break;
                }
        }
        if(flag) c++;
    }
   cout<<c;

    return 0;
}
