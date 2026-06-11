#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char S[200000];
    cin>>S;
    int len=strlen(S);
    int ans=len,Max;
    for(int i=1;i<len;i++)
    {
        if(S[i]!=S[i-1])
        {
            Max=max(i,len-i);
            ans=min(Max,ans);
        }
    }
    cout<<ans;
    return 0;
}
