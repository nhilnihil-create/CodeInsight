#include <bits/stdc++.h>
using namespace std;
int main(){

int a, b, c, d, N;
cin >> N;
a=N/1000;
b=(N%1000)/100;
c=((N%1000)%100)/10;
d=N%10;
if(N%1111==0){
cout <<"Yes" << endl;
}
else if(a==b && b==c){
cout <<"Yes" << endl;
}
else if (b==c && c==d){
cout << "Yes" << endl;
}
else{
cout <<"No" << endl;
}
}