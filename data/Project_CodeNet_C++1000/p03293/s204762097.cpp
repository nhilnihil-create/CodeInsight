#include <iostream>

using namespace std;

int main()
{
string x,y;
cin>>x>>y;

int c=x.length();
for(int i=0;i<c;i++){
if(x==y){
cout<<"Yes"<<endl;
break;
}

char z;
z=x[x.length()-1];
x.erase(x.end()-1);
x.insert(x.begin(),z);
if(i+1==c){cout<<"No"<<endl;}
}


    return 0;
}