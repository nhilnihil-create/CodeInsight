#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j,c=0,k;
    string s;
    cin >> s;
    k=s.size();
    if(s[0]!='A' || s[1]<'a' || s[k-1]<'a' )
    {
        cout << "WA" << endl;
        return 0;
    }
  
    for(i=2;i<k-1;i++)
    {
        if(s[i]=='C')
        {
            c++;
            if(c==2)
            {
                cout << "WA" << endl;
                return 0;
            }
            continue;
        }
        if(s[i]<'a')
        {
            cout << "WA" << endl;
            return 0;
        }
    }
    if(c==1)
    {
        cout << "AC" << endl;
    }
    else
    {
        cout << "WA" << endl;
    }
    return 0;

}
