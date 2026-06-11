#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;string s;int q;
    cin>>n;cin>>s;cin>>q;
    while(q--)
    {
        int k;
        scanf("%d",&k);
        ll d=0,dm=0,dmc=0,mc=0,c=0,m=0;
        int i;
        ll ans=0;
        for(i=0;i<k;i++)
        {
            if(s[i]=='D'){
                d++;
            }else if(s[i]=='M'){
                dm+=d;m++;
            }else if(s[i]=='C'){
                dmc+=dm;c++;
            }
        }
        ans+=dmc;
        for(;i<n;i++){
            switch(s[i-k]){
                case 'D':dmc-=mc;dm-=m;d--;break;
                case 'M':mc-=c;m--;break;
                case 'C':c--;break;
            }
            if(s[i]=='D'){
                d++;
            }else if(s[i]=='M'){
                dm+=d;m++;
            }else if(s[i]=='C'){
                dmc+=dm;mc+=m;c++;ans+=dm;
            }
        }
        printf("%lld\n",ans);
    }
}
