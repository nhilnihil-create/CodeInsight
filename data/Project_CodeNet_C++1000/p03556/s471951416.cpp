#include<bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
ll n;
int main(){
	cin>>n;
	for(int i=1;i<=32000;i++) 
		if(i*i>n) {cout<<(i-1)*(i-1);return 0;}
    return 0;
}