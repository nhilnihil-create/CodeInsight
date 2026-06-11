#include <iostream>

using namespace std;
int cost(int A,int B){
 if(A>=13){
   return B;
 }
else if(A>=6&&A<=12){
    return B/2;
}
else if(A<=5){
    return 0;
}
}


int main()
{
int a,b;
cin>>a>>b;
cout<<cost(a,b)<<endl;
    return 0;
}
