#include <iostream>
using namespace std;
int main (){
int a,b,c;
cin>>a>>b>>c;


if (a==b&a!=c){
    cout<<c;
}
else if (a==c&a!=b){
    cout<<b;
}
else if (b==a&b!=c){
    cout<<c;
}
else if (b==c&b!=a){
    cout<<a;
}
else if (c==a&c!=b){
    cout<<b;
}
else if (c==b&c!=a){
    cout<<a;
}
return 0;



}
