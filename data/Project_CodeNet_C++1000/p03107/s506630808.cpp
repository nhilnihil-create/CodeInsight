#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cnt=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='1') cnt++;
        else cnt--;
    }
    if(cnt<0) cnt = cnt*(-1);
    cout<<s.size()-cnt<<endl;
}
