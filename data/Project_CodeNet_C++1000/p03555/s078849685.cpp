#include <iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    
 string n,m;
 cin>>n>>m;

 if((n[0]==m[2])&&(n[1]==m[1])&&(n[2]==m[0]))
cout<<"YES"<<endl;
 else
 cout<<"NO"<<endl;

    return 0;
}
