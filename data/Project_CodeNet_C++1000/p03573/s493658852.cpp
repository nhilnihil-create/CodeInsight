#include <iostream>

using namespace std;

int main()
{
    int a,b,c ;
   
    cin>>a>>b>>c;
    if (a>100|| b>100 ||c>100) {
        cout<<"error";
        return 0 ;
    }
    if (a<-100|| b<-100 || c<-100) {
        cout<<"error";
        return 0 ;
    }
    if(a==b) cout<<c;
    if(a==c) cout<<b;
    if(b==c) cout<<a;

    return 0;
}

