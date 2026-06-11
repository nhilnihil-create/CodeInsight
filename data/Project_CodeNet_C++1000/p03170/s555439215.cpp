#include <bits/stdc++.h>

using namespace std;

int n;
int a[100];

vector<int> d(1e5 + 1, -1);

int fun(int k){
	if(d[k] != -1) return d[k];
	int ch = 0;
	for(int i = 0; i < n; ++i){
		if(k < a[i]) break;
		if(!fun(k - a[i])){
			ch = 1; break;
		}
	}
	d[k] = ch;
	return ch;
}


int main(){
	int k; cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << (fun(k)?"First":"Second");
}