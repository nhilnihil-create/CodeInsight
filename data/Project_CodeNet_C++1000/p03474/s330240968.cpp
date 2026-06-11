#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b ;
    string s;
    cin >> s;
    if(a+b+1==s.size())
    {
        bool mrk = 0 ;

        for(int i=0; i<s.size(); i++)
        {
             if(i==a && s[i]!='-'){mrk = 1;break;}
             if(i!=a)
             {
                 if(s[i]>='0' && s[i]<='9')continue;
                 else {mrk = 1;break;}
             }
        }
        if(!mrk)cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    else cout << "No" << endl;

}
