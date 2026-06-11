#include<iostream>
using namespace std;
int main()
{
    int w,j=0;
    char a[1100];
    string s;
    cin>>s;
    cin>>w;
    for(int i=0;i<s.size();i+=w)
    {
        a[j++]=s[i];
    }
    for(int k=0;k<j;k++)
    {
        cout<<a[k];
    }
    return 0;
}
