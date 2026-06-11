#include <iostream>

using namespace std;

int main()
{
   int A,B,C;
   cin >>A>>B>>C;
   A<=100 && A>=-100 ;
   B<=100 && B>=-100 ;
   C<=100 && C>=-100 ;
   if (A==B) cout<<C;
   else if (A==C) cout<<B;
   else cout<<A;

    return 0;
}