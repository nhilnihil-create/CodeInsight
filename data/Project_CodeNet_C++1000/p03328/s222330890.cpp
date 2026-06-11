#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int def=b-a;
    int b1=def*(def+1)/2;
    cout<<b1-b<<endl;
    return 0;
}