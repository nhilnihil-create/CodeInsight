#include <bits/stdc++.h>
using namespace std;

int main() {
    string s,p,q;
    int m,y;
    cin>>s;
   m = (s[0]-'0')*(10) + (s[1]-'0');
   y = (s[2]-'0')*(10) + (s[3]-'0');
    if((m<=0 || m>=13) && (y<=0 || y>=13))
       {
           cout<<"NA"<<endl;
       }
       else if((m>=1 && m<=12) &&(y>=1 && y<=12))
        {
            cout<<"AMBIGUOUS"<<endl;
        }
        else if(m>=1 && m<=12)
        {
            cout<<"MMYY"<<endl;
        }
        else if(y>=1 && y<=12)
        {
            cout<<"YYMM"<<endl;
        }

}
