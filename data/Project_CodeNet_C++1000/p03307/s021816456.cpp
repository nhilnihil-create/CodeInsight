#include<iostream>
 
using namespace std;
 
int main(){
    long long n;
    cin >> n;
    if(n%2==1)printf("%lld\n", n*2);
    else printf("%lld\n", n);
    return 0;
}