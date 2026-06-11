/*
/ ATcoder /
ID : lalit kumar
TASK : A
LANG : c++14
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

 string s;
 cin>>s;
 int n = (int)s.size();
 int a[26]={0};
 for(int i =0;i<n;i++)
 {
     a[s[i]-'a']++;
 }
if(a[0] && a[1] && a[2]) cout<<"Yes\n";
else cout<<"No\n";
 return 0;
}