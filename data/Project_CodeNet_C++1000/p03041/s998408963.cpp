#include <iostream>

using namespace std;

int main()
{
    int n,k,sum;
    string s;
    cin>>n>>k>>s;
    sum=int(s[k-1]);
    sum+=32;
    s[k-1]=(char)sum;
    cout<<s;
}