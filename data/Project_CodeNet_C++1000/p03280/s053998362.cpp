#include<iostream>
using namespace std;
int garden(int x,int y);
int main()
{
	int x,y;
	cin>>x>>y;
	cout<<garden(x,y)<<endl;
}
int garden(int x,int y)
{
    return x*y-(x+y)+1;
}
