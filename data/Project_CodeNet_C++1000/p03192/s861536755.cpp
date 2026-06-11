#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x;
int main(){
	cin>>x;
	cout<<(x%10==2)+(x%100/10==2)+(x%1000/100==2)+(x/1000==2);
	return 0;
}