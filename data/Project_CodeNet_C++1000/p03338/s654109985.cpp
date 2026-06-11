#include <bits/stdc++.h>
using namespace std;
int main(void){
    int i=0,n,d,j,k,saidai=0,c=0,l;
    string s;
    bool used[26];
    cin >> n >> s;
    for(i=0;i<n;i++)
    {
        for(l=0;l<26;l++)
        {
            used[l]=false;
        }
        for(j=0;j<i;j++)
        {
            char h=s.at(j);
            if(used[h-'a']==false)
               {
                   used[h-'a']=true;
               }
            else
            {
                continue;
            }
            for(k=i;k<n;k++)
            {
                if(s.at(j)==s.at(k) )
                {
                    c++;
                    break;
                }
            }
        }
        if(saidai<c)
        {
            saidai=c;
        }
        c=0;
    }
    cout << saidai << endl;
    return 0;
}
