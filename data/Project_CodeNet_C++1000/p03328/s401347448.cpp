#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int dif = b-a;
    int sum = dif*(dif+1)/2;
    cout<<sum-b;
    
    return 0;
}