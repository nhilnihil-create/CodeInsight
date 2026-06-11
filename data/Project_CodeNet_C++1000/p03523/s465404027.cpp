#include<string>
#include<iostream>
using namespace std;
string x,y="KIHBR";
int cnt;
bool ok=1;
int main()
{
    cin>>x;
    if(x.size()>9) printf("NO\n");
    else
    {
        for(int i=0;i<x.size();i++)
        {
            if(i>=1 && (x[i]==x[i-1] || x[i]=='A' && (x[i-1]=='I' || x[i-1]=='K') ) ) 
            {
                ok=0;
                break;
            }
            if(x[i]=='A') continue;
            if(x[i]!=y[cnt])
            {
                ok = 0;
                break;
            }
            else 
            {
                cnt++;
            }
        }
       // printf("%d\n",cnt);
        if(cnt!=y.size()) ok = 0;
        printf("%s\n",ok?"YES":"NO");
    }
    return 0;
}
