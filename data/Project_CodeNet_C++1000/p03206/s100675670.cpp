#include <bits/stdc++.h>
using namespace std;
int main()
{
	int day=0;
 	 cin>>day;
  string daysname="Christmas";
  for(int i=25;i>day;i--){
     daysname += " Eve";
  }
  	cout<<daysname<<endl;
}