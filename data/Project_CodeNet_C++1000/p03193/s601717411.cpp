#include<iostream>

using namespace std;

int main(){
    int n,h,w;
    cin>>n>>h>>w;
    int a,b,s=0;
    while(n--){
        cin>>a>>b;
        if(a>=h && b>=w) s++;
    }
    cout<<s<<endl;
    return 0;
}