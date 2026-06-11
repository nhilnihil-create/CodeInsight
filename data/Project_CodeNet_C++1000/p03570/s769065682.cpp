#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char str[maxn];
unordered_map<int, int>mi;
int get(int x)
{
    if(mi.count(x))
    {
        return mi[x];   
    }
    return maxn;
}
void add(int x, int val)
{
    if(!mi.count(x))
    {
        mi[x]=val;
    }
    else mi[x]=min(mi[x], val);
}
int main()
{
    scanf("%s", str);
    int i, j;
    int dp=0, mask=0;
    for(i=0; str[i]; i++)
    {
        add(mask, dp);    
        mask^=1<<(str[i]-'a');
        dp=get(mask)+1;
        for(j=0; j<26; j++)
        {
            dp=min(dp, get(mask^(1<<j))+1);
        }
    }
    printf("%d\n", dp);

}
