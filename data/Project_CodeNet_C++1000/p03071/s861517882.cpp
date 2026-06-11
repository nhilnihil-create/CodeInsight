#include<bits/stdc++.h>

using namespace std;

int main(){
int a,b;
cin>> a>> b;
int c =2;
int sum = 0;
while(c--){
if(a>b){ sum+=a;a--;}
else {sum+=b;b--;}
}
cout << sum;
}