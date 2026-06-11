#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a,b;
	cin>>a>>b;
	if(a+b==15)cout<<"+"<<endl;
	else if(a*b==15)cout<<"*"<<endl;
	else cout<<"x"<<endl;
	return 0;
}