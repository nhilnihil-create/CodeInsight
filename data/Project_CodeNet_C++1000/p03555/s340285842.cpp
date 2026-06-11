#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,s;
    cin>>a>>s;
    cout<<(a[0]==s[2]&&s[0]==a[2]&&a[1]==s[1]?"YES":"NO")<<endl;
}
