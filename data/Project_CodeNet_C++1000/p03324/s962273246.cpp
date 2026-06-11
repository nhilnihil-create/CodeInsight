#include <iostream>
using namespace std;
int main() {
   int n,d;
   cin>>n>>d;
   string str;
   if(d!=100)
   str=to_string(d);
   else str+=to_string(101);
   for(int i=0;i<n;i++)
   str+="00";
   cout<<str;
}
