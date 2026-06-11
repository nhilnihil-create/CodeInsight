#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n,i,k,l;

    while(cin>>s)
    {
        cin>>n;
        l = s.size();
        if(n==1)
        {
            cout<<s<<endl;
            continue;
        }

        for(i=1;i<=l;i++)
        {
            if(i%n==1)
            {
                cout<<s[i-1];
            }

        }
        cout<<endl;
        s.clear();

    }










return 0;
}
