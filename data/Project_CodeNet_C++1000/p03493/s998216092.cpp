#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long int ll;
 
int main()
{
 string s;
 cin>>s;
 int ans=0;
 if(s[0]=='1'){ans++;}
 if(s[1]=='1'){ans++;}
 if(s[2]=='1'){ans++;}
 printf("%d",ans);
} 