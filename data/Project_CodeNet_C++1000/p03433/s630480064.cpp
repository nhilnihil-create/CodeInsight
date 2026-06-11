#include<iostream>
using namespace std;
int main(){
    int n,a;
    cin>>n>>a;
    int rem=n%500;
    if(rem>a)
    {
        cout<<"No\n";
    }
    else
    {
        cout<<"Yes\n";
    }
}