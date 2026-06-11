#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,b,a)     for(int i=b;i>=a;i--)

int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n%111==0)
        cout<<n;
    else
        cout<<(n/111+1)*111;
}

