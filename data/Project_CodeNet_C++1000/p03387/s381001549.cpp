#include<bits/stdc++.h>

using namespace std;

int main() {
int a,b,c;
cin>>a>>b>>c;
int maxx=max(a,max(b,c));
if(3*maxx%2==(a+b+c)%2){
   cout<<(3*maxx-(a+b+c))/2<<endl;
}
else{
   cout<<(3*(maxx+1)-(a+b+c))/2<<endl;
}
   return 0;
}




