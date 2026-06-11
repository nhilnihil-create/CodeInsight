#include<bits/stdc++.h>
using namespace std;
int fac(int a);
int main(){
    int a,b;
    cin>>a>>b;
    cout<<fac(b-a-1)-a<<endl;
     return 0;
}
int fac(int a){
    return int(a*(a+1)*0.5);
}