#include<iostream>
using namespace std;
int digit(int a){
    int resto,div,sum=0;
    while(1){
        resto=a%10;
    div=a/10;
    sum=sum+resto;
    a=div;
    if(a==0)break;
    }
    return sum;
 
}
main()
{
    int n,i=1,sum=0,min=1000000,a,b;
    cin >> n;
    while(i<n){
    a=i;
    b=n-i;
 
    sum=digit(a)+digit(b);
    if(sum<min)min=sum;
    i++;
 
 
    }
    cout << min << endl;
    return 0;
}