#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int siz = s.size(),c=0;
    bool flag = true;
    for(int i=0; i<siz; i++)
    {
        if(i == 0)
        {
            if(s[i]!='A')
            {
                flag=false;
            }
        }
        if(i>0&&i<siz&&s[i]!='C')
        {
            if(!(s[i]>='a'&&s[i]<='z'))
            {
                flag = false;
            }

        }
        if(i>1&&i<siz-1 && s[i]=='C')
            ++c;
    }
    if(c!=1)
    {
        flag = false;
    }
    if(flag)
        cout<<"AC";
    else
        cout<<"WA";

}
