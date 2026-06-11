#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

bitset < 10 > v;
char w;

int main(){
	v.reset();
	for(int i=1;i<=3;i++){
		cin>>w;
		if(w=='o')v[i]=1;
		else v[i]=0;
	}
	cout<<v.count()*100+700;
	return 0;
}