#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(0!=a%2&0!=b%2){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}