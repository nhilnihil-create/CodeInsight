#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    if(s[a]=='-')
    {
        int flag=1;
        for(int i=0;i<s.length();i++)
        {
            if(i==a)
                continue;
            if(!(s[i]>='0'&&s[i]<='9')){
                flag=0;break;
            }

        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
     else
        cout<<"No"<<endl;


}
