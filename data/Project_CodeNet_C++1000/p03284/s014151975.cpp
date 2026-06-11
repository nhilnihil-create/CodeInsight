#include <iostream>
#include<cmath>
using namespace std;
int main(){
int a,b,x,y=0;
cin>>a>>b;
x=a%b;
while(x>=0){
		if(x==0){
		
			cout<<false;
			break;
			}
		else if(x>0)  {
			if(x%b==x)
			y=1+a/b;
			cout<<abs(y-a/b);
			break;
			
				
		
		
			
		}		
				
			
		}
}


