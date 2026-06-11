#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

inline int read();

string a;

int main()
{
    cin>>a;
    for(int s=0;s<a.size()-8;s++)cout<<a[s];
    cout<<endl;
    return 0;
}

inline int read() {
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0' || c>'9') {if(c=='-') flag=1; c=getchar();}
    while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
    return flag?-x:x;
}
