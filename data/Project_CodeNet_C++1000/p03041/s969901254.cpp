#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{

   int n,k;
   scanf("%d %d",&n,&k);
   char s[100];
   scanf("%s",&s);
   s[k-1]= 'a'+s[k-1]-'A';
   printf("%s",s);
}
