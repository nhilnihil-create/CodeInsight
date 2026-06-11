#include <bits/stdc++.h>
using namespace std;

int main() {
long long x,y;
cin>>x>>y;
int a=0;
while(y>=x){
x*=2;
a++;
}
cout<<a<<endl;
return 0; 
}

