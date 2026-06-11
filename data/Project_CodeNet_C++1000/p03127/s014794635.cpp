#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,y;
	cin>>n;
	priority_queue<int>q;
	for(int i=0;i<n;i++){cin>>x;q.push(x);}
	
	while(q.size()>1)
	{
		x=q.top();q.pop();
		y=q.top();q.pop();
		x%=y;
		if(x)q.push(x);
		q.push(y);
	}
	cout<<q.top()<<endl;
}

