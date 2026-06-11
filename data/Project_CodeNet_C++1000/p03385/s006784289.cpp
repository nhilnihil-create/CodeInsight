#include <iostream>
using namespace std;
int main()
{
    char a,b,c,ap=0,bp=0,cp=0;
    cin>>a>>b>>c;
    if(a=='a'){ap++;}
    if(a=='b'){bp++;}
    if(a=='c'){cp++;}
     if(b=='a'){ap++;}
    if(b=='b'){bp++;}
    if(b=='c'){cp++;}
     if(c=='a'){ap++;}
    if(c=='b'){bp++;}
    if(c=='c'){cp++;}
    if(ap==1 && bp==1 && cp==1)
    {
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}
