#include <iostream>

using namespace std;

int main()
{
   int n , m ;
   cin>>n>>m;
   if(n+m==15) {
    cout<<"+";
    return 0;
   }
   if(n*m==15) {
    cout<<"*";
    return 0;
   }
   cout<<"x";


    return 0;
}
