#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,A,B;
	cin>>N>>A>>B;
	int ansmax,ansmin;
	ansmax=min(A,B);
	ansmin=max(0,A+B-N);
	cout<<ansmax<<' '<<ansmin<<endl;
}