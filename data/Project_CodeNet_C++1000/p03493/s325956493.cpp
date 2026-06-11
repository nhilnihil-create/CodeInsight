#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;
    int cnt=0;
    if(s[0]=='1')cnt++;
    if(s[1]=='1')cnt++;
    if(s[2]=='1')cnt++;
    cout<<cnt<<endl;
}
