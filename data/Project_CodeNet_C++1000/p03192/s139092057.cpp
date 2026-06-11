#include <iostream>
using namespace std;
int main()
{
      int sum=0,n,c=0;
      cin>>n;
      while(n>0){
            sum=n%10;

        if(sum==2){
            c++;
        }

            n=n/10;
      }

      cout<<c<<endl;


   return 0;

      }


