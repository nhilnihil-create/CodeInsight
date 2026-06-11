#include <iostream>
using namespace std;

int main(){
int a,b,maior,soma;

cin>>a>>b;
soma=a+b;
maior=soma;
soma=a-b;
if (soma>maior){maior=soma;}
soma=a*b;
if (soma>maior){maior=soma;}
cout<<maior<<endl;

return 0;
}
