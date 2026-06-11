#include<bits/stdc++.h>
using namespace std;
int d[100009];
int main()
{
	string s;
	cin>>s;
	int an=0;
	stack<char>st;
	for(char i:s)
	{
		if(st.empty())st.push(i);
		else if(st.top()==i)st.push(i);
		else {st.pop();an+=2;}
	
	}
	cout<<an<<endl;
}

