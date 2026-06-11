#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll k;
    cin>>k;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')k-=1;
        else k=0;
        if(k==0){cout<<s[i];return 0;}
    }
}
