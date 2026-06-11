#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    int A, B, K, itr;
    int count = 0;
   
    cin >> A >> B >> K;
for (int i = min(A,B); i >= 1; i--)
{
   if ( A%i==0 && B%i==0)
   {
       count++;
   }
   if (count==K)
   {
           
    cout << i << endl;
    return 0;
}
   }

}


