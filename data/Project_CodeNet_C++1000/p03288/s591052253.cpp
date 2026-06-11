#include<iostream>;
using namespace std;
int n;
int main()
{
cin>>n;
if(n<1200)cout<<"ABC"<<endl;
else if(n>=2800)cout<<"AGC"<<endl;
else cout<<"ARC"<<endl;
return 0;
}