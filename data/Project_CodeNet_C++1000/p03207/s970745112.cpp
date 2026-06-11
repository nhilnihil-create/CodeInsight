#include<bits/stdc++.h>
using namespace std;

int main(){
  	long n;
  	cin >> n;
  	vector<long> a(n);
  	for(int i=0;i<n;i++){
    	cin >> a[i];
    }
  	auto m=max_element(a.begin(),a.end());
  	*m=*m/2;
  	long sum=0;
  	for(auto i:a){
    	sum+=i;
    }
  	cout << sum;
}
