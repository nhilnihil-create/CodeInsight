#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<math.h>
#include<queue>
#define inf 0x3f3f3f
#define M 200000
#define ll  long long
using namespace std;
string s;
int a[M];
int main()
{
    cin>>s;
    int len=s.size();
    int i,j;
    int count=0;
    for(i=0;i<len;i++)
    {
        if(s[i]!=s[i-1])
        {
            a[count++]=max(i,len-i);

        }
    }
 sort(a,a+count);
 cout<<a[0]<<endl;
}
