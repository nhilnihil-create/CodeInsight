#include <iostream>
#include <cmath>
using namespace std;
int main ( )
{ int A ,B;
cin >>A>>B;
cout<< max(A,B) + max(max(A,B)-1 , min(A,B));
return 0;
}