#include<iostream>
using namespace std;
int digits(int a)
{
    int sum=0;
    while(a!=0){
        sum+=a%10;
        a/=10;
    }
    return sum;
}
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int sum=0;
    for(int i=0;i<=n;i++)
    {
        int totaldigits=digits(i);
        if(totaldigits>=a&&totaldigits<=b){
            sum+=i;

        }
    }
    cout<<sum<<"\n";
}