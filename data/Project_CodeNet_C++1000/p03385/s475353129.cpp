#include<iostream>
using namespace std;
int main()
{

    char s[4];
    int a=0, b=0, c=0;

    cin>>s;

    for(int i=0; i<3; i++) if(s[i]=='a')
        {
            a=1;
            break;
        }
    for(int i=0; i<3; i++) if(s[i]=='b')
        {
            b=1;
            break;
        }
    for(int i=0; i<3; i++) if(s[i]=='c')
        {
            c=1;
            break;
        }

    if(a==1 && b==1 && c==1)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    return 0;
}
