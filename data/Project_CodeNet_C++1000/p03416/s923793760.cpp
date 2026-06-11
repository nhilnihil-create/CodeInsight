#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string int_to_string(int x)
{
    string s;
    while(x!=0)
    {
        s.push_back(48+x%10);
        x/=10;
    }
    return s;
}
int main()
{
    int a, b,i,cnt=0,l,j,k,flag;
    cin >>a >> b;
    string x, y;
    for(i=a;i<=b;i++)
    {
       x= int_to_string(i);
       l=x.size();
       flag=1;
       for(j=0,k=l-1; j<=l-1/2;j++,k--) if(x[j]!=x[k]){flag=0;break;}
       if(flag==1) cnt++;
    }
    cout <<cnt;
}
