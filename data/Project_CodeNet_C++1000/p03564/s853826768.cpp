#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int current=1;
    while(n--)
    {
        if(current*2<current+k)
        {
            current*=2;
        }
        else
        {
            current+=k;
        }
    }
    cout<<current;

}