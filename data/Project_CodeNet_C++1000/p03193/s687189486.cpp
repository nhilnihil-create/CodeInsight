#include<iostream>
using namespace std;
int n,h,w,a,b,c,i;
int main()
{
	for(cin>>n>>h>>w;i<n;i++)cin>>a>>b,c+=!(a<h||b<w);
	cout<<c<<endl;
}