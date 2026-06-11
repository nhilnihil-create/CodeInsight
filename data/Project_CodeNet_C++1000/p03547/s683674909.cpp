//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
char x,y;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>x>>y;
	if(x<y)
	cout<<"<";
	else if(x>y)
	cout<<">";
	else
	cout<<"=";
	return 0;
}
