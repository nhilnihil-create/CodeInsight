#include <bits/stdc++.h>
using namespace std;

int N,A,B;

int main(){
	cin>>N>>A>>B;
	cout<<((B-A)%2==0 ? "Alice" : "Borys")<<'\n';
}