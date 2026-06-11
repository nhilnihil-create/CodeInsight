#include <iostream>

using namespace std;

int main()
{
    int a,b,c ;
    cin>>a;
    cin>>b;
    cin>>c;
    if(a==c){
       cout<<b;
    }
     if(a==b){
       cout<<c;
    }
     if(b==c){
       cout<<a;
    }
    return 0;
}
