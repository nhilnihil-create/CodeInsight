#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len = s.size();
    int cnt=0,a[len+1]={0};
    for(int i=1; i<len; i++)
    {
        if(s[i]==s[i-1]){
            //a[cnt]++;
            cnt++;
            if(s[i]=='0')s[i]='1';
            else if(s[i]=='1')s[i]='0';
        }
        //else cnt++;
    }
    //cnt++;
    //cout<<s<<endl;
    //int ans = *max_element(a,a+cnt);
    cout<<cnt<<endl;
    return 0;
}
