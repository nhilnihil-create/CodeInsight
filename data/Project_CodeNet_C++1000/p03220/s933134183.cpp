#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int abs(int x){
    if(x<0) return -x;
    else return x;
}
int main() {
    int n,t,a;
    cin>>n>>t>>a;
    vector<float> h(n);
    for(int i=0;i<n;i++){
       cin>>h.at(i); 
       h.at(i)=t-h.at(i)*0.006;
    } 
    float minimum=10000000;
    int index=0;
    for(int i=0;i<n;i++){
        float mini_if=0;
        mini_if=abs(a-h.at(i));
        if(minimum>=mini_if){
            minimum=mini_if;
            index=i;
        }
    }
    cout<<index+1<<endl;


}