#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	cout<<(a+b<=2*c?a*x+b*y:x>y?a<=2*c?a*(x-y)+2*c*y:2*c*x:b<=2*c?b*(y-x)+2*c*x:2*c*y)<<endl;
}
