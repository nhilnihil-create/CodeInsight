#include <iostream>

using namespace std;

int main()
{

string x;
cin>>x;
int count=0,small=0;


for(int i=2;i<x.length()-1;i++){
if(x[i]=='C'){count++;}
}
for(int i=0;i<x.length();i++){

    if(x[i]>96&&x[i]<123){small++;}
}
if(x[0]=='A'&&(small==x.length()-2)&&count==1){cout<<"AC"<<endl;}


else{cout<<"WA"<<endl;}

    return 0;
}
