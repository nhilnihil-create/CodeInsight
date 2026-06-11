#include<bits/stdc++.h>
using namespace std;main(){string s;cin>>s;int l=s.size(),r=(l+1)/2;while(s[r]==s[r-1]&&s[r]==s[l-r-1])++r;cout<<r;}