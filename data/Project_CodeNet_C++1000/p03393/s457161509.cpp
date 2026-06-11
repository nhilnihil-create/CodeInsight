#include <bits/stdc++.h>
using namespace std;
int a[256];char s[256];
int main()
{
    cin>>s;int l=1;
    for(int i=0; s[i]; i++)a[s[i]]=1,l++;
    for(int c='z'; c>='a'; c--)
        if(!a[c])s[l++]=c;
    if(next_permutation(s,s+l)) cout<<s;
    else cout<<-1;
}