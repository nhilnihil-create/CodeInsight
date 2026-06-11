#include <iostream>
using namespace std;

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int left=a+b,right=c+d;
    cout<<(left>right?"Left":left<right?"Right":"Balanced")<<endl;
}
