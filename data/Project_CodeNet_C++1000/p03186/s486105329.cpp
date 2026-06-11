#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c,result,K;
	cin>>a>>b>>c;
	result=min(a,c);
	a-=result;
  	c-=result;
	K=min(b,c);
	result+=K+b;
	b-=K;
  	c-=K;
	if(c)
      result++;
	cout<<result;
    return 0;
}
