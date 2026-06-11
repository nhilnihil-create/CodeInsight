#include<bits/stdc++.h>
using namespace std;
int main()
{
        int a,b;
	char c;
	cin>>a>>b;;
	for(int i=0;i<a+b+1;i++){
		cin>>c;
		if(c=='-' && i!=a || i==a && c!='-'){
		        cout<<"No"<<endl;
		        return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
