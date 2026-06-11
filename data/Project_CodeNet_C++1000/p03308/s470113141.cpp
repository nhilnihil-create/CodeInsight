#include<iostream>
using namespace std;

int main(){
    long long a,b;
    cin>>a;
    long long d=0;
    long long e=1e9;
    for(long long i=0;i<a;i++){
        cin>>b;
        d=max(b,d);
        e=min(b,e);
    }
    cout<<d-e;
}