#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   string s;
   cin >> s;
   string result;
   if (s=="abc" || s== "acb" || s== "bac" || s=="bca" || s=="cab" || s=="cba"){
    result= "Yes";
   }else {
   result = "No";}
   cout <<result;
    return 0;
}
