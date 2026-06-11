#include <iostream>
using namespace std;int main(void){int n;cin>>n;int a=n%111==0?n:n+(111-(n%111));cout<<a<<"\n";}