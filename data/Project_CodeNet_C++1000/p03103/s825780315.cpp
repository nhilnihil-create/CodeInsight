#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m;
	cin >>n>>m;
	vector<pair<long long, long long>> stores;
	
	while (n--){
		long long a, b;
		cin >> a>> b;
		stores.push_back(make_pair(a,b));
	}
	sort (stores.begin(), stores.end());
	long long sum=0;
	long long money=0;
	int i=0;
	while (sum<m){
		sum+= stores[i].second;	//sumamos la cantidad que llevamos
		money+= stores[i].first*stores[i].second; //sumamos el dinero
		++i;
	}
	sum -=m; //la suma que tenemos menos la requerida para ver cuantos sobran
	if (sum>0)
		money-= stores[i-1].first*sum; //le restamos el dinero de las bebidas extra
	cout << money<<'\n';
}