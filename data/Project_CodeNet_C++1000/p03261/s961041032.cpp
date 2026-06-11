#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    map<str, int> m;

    bool ans=true;

    str bw="";

    for(int i=0;i<n;i++)
    {
        str w;
        cin>>w;
        if(bw!="")
        {
            if(bw[bw.size()-1]!=w[0])
            {
                ans=false;
                break;
            }
        }
        bw=w;
        if(m[w]>0)
        {
            ans=false;
            break;
        }
        m[w]++;
    }

    puts(ans?"Yes":"No");

    return 0;
}
