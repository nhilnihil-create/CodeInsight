#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    long long d=max({a,b,c});
    long long e=min({a,b,c});
    cout<<d-e;
}