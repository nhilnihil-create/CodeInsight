#include <iostream>
using namespace std;

int main(){

int a,b,c,k,maior=0,soma=0,n=0;

cin >> a >> b >> c ;
cin >> k;

while(k>0){
        k--;
        soma = a+b+2*c;
        maior = soma;
        if(2*a+b+c>maior){maior=2*a+b+c;n=1;}
        if (a+2*b+c>maior){maior=a+2*b+c;n=2;}

        if (n==0){c=2*c;}
        if (n==1){a=2*a;}
        if (n==2){b=2*b;}

}



cout<<maior<<endl;



return 0;
}
