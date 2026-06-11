#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    s.erase(4,1);
    s.erase(6,1);
    long long int ans=atoi(s.c_str());
    if(ans<=20190430) cout<<"Heisei";
    else cout<<"TBD";
}