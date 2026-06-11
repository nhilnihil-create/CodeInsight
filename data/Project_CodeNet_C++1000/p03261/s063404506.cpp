#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    vector<string> str(n);
    for(i=0;i<n;i++)
    {
        cin>>str[i];
    }
    int p=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j) continue;
            if(str[i]==str[j])
                p=0;
        }
        if(str[i][0]!=str[i-1][str[i-1].size()-1])
            p=0;
    }
    if(p)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
