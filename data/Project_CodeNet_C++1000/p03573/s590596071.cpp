#include<bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	if(a==b) cout<<c;
	if(b==c) cout<<a;
	if(a==c) cout<<b;
    return 0;
}