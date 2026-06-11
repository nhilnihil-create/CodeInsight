#include <iostream>
using namespace std;
int main()
{
	 int x , y , z ;
	 cin>>x>>y>>z ;
	 if (x==y && x!=z)
		 cout<<z ;
	 else if (x==z && z!=y) 
		 cout<<y ;
	 else if (y==z && y!=x) 
		 cout<<x ;
	 return 0;
}