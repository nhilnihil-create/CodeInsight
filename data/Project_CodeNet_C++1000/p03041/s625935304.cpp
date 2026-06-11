
#include<iostream>
using namespace std;
int main()
{
    int n,k;
    char ch;
    cin>>n;
    cin>>k;
    string s;
    cin>>s;
    s[k-1]=tolower(s[k-1]);
    cout<<s;
return 0;

}