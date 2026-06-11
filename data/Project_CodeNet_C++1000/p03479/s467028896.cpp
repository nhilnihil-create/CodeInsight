#include<iostream>
using namespace std;
int main(void){
    long long x,y;
    cin>>x>>y;
    int cnt(1);
    while(x*2<=y){
        x *= 2;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}