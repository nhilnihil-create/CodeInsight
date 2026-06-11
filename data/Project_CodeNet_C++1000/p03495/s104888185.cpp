#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a.at(i);
	}
	vector<int> vec(n);
	for(int i=0; i<n; i++){
		vec.at(a.at(i)-1)++;
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	int num=0;
	for(int i=0; i<n; i++){
		if(vec.at(i)!=0){
			num++;
		}
		if(vec.at(i)==0){
			break;
		}
	}
	vector<int> sam(num);
	for(int i=0; i<num; i++){
		sam.at(i)=vec.at(i);
	}
	reverse(sam.begin(), sam.end());
	int ans=num-k;
	if(ans<=0){
		ans=0;
	}
	else {
		int sum=0;
		for(int i=0; i<ans; i++){
			sum += sam.at(i);
		}
		ans = sum;
	}
	cout << ans << endl;
}
