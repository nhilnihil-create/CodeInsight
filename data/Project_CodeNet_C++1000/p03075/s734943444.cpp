#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> ant;
	for (int i=0; i<5; i++){
		int x;
		cin>>x;
		ant.push_back(x);
	}
	int k;
	cin>>k;
	if (ant[4]-ant[0]>k) cout<<":(";
	else cout<<"Yay!";
	cout<<endl;
}