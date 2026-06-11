#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   
  string a,b;
  cin>>a>>b;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end(),greater<char>());
 
  puts(a<b?"Yes":"No");
}