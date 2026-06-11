#include<iostream>
using namespace std;
int main(){
    int a,b,k;
    cin>>a>>b>>k;
    int index=0;
    int temp=k;
    for(index=a;index<=b&&temp>0;index++)
    {
        cout<<index<<"\n";
        temp--;
    }
    temp=k;
    for(int i=max(index,b-k+1);i<=b&&temp>0;i++)
    {
        cout<<i<<"\n";
        temp--;
    }
}