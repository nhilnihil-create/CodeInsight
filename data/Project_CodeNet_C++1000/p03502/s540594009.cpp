#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int abs(int x){
    if(x<0) return -x;
    else return x;
}
int sum_keta(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main() {
    int n;
    cin>>n;
    if(n%sum_keta(n)==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}