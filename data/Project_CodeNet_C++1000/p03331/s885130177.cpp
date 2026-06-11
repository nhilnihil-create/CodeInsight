#include <iostream>
using namespace std;
int a=1,b=0,t,sum=0,n,m,soma1,soma2=0,sum1;

int dig(int l);

int main(){
cin>>n;
b=n-1;
soma2=dig(a)+dig(b);


for(int j=0;j<=(n/2)-2;j++){
    a++;
    b=n-a;
    soma1 = dig(a)+dig(b);
    if (soma1<soma2){soma2=soma1;}
    soma1=0;

}
cout<<soma2<<endl;
return 0;
}

int dig(int l){
while(l>0){
        m=l%10;
        sum=sum+m;
        l=l/10;}
sum1=sum;
sum=0;
return sum1;
}
