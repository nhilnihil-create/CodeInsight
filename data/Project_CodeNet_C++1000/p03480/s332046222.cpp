#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include<iostream>
#include<vector>
#define MAXN 20000
#define INF 0x3f3f3f3f
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len=s.size();
    int x1,x2;
    int ans=0;
    if(len%2)x1=x2=len/2;
    else x1=len/2-1,x2=len/2;
    for(int i=x1,j=x2;i>=0&&j<len;i--,j++)
    {
        if(s[i]!=s[i+1]&&i!=j)break;
        if(s[i]==s[j])
        {

            if(i==j)ans++;
            else ans+=2;
        }
        else break;


    }
    //cout<<ans<<endl;
    cout<<(ans+len)/2;
}
///10100
