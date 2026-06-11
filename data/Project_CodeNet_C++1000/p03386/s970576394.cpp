#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,k;
	set<int> st;
	cin>>a>>b>>k;
	for(int i=0;i<k;i++){
		if(a+i>b||b-i<a) continue;
		st.insert(a+i);
		st.insert(b-i);
	}
	for(set<int>::iterator it=st.begin();it!=st.end();it++)
		cout<<*it<<endl;
	return 0;
}