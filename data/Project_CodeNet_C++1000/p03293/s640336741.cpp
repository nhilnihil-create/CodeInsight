#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    bool chk=false;
    string S,T;
    cin >> S >> T;
    char tmp;
    for(int i=0; i<S.size(); i++)
    {
        if(S==T)
        {
            chk=true;
            break;
        }
        for (int j=0; j<S.size(); j++)
        {
            if(j==0) 
            {
                tmp=T.at(0);
            }
            if(j==S.size()-1)
            {
                T.at(j)=tmp;
                continue;
            }
            T.at(j)=T.at(j+1);            
        }
    }
    if(chk)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}