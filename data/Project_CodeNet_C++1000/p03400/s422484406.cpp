#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define endl '\n'
using namespace std;
int main()
{
	int n,d,x;
	cin>>n>>d>>x;
	int v[101];
	for(int i = 0; i<n; i++)
		cin>>v[i];
	int tot = 0;
	for(int stu = 0; stu<n; stu++){
		int a = 1,b = v[stu];
		tot++;
		while(a <= d){
			v[stu]=a+b;
			if(v[stu]<=d)tot++,a = v[stu];
			else break;
		}
	}
	cout<<tot+x<<endl;
	return 0;
}