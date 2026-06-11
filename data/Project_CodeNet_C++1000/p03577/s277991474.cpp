#include<bits/stdc++.h>
using namespace std;
char a[100000];int i,k;
int main()
{scanf("%s",a);
 k=strlen(a);
 k=k-8;
 for(i=0;i<k;i++)
  cout<<a[i];
 return 0;
}