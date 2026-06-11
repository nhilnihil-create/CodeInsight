#include <iostream>;
using namespace std;
int main(){
int k,n;
cin>>k>>n;
if (k%n!=0){cout<<1;}
else if(k%n==0){cout<<0;}
return 0;
}