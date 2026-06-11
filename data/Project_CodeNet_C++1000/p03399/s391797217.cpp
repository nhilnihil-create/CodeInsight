#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,min1=0,min2=0;
    cin>>a>>b>>c>>d;

    if(a>b){
    min1=b;

    }if(a<b){
        min1=a;

    } if(c>d){

        min2=d;


    } if(c<d){
        min2=c;

    } if(a==b){
        min1=a;


    } if(c==d){
        min2=c;

    }

    cout<<min1+min2<<endl;

    return 0;

}









