#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	if(n==3){
		cout << 2 << " " << 3 << " " << 25 << endl;
		return 0;
	}
	if(n%2==0){
		int cnt=n/8;
		int q=n%8;
		for(int i=0;i<cnt;i++){
			int j=12*i;
			cout << 2+j << " " << 10+j << " " << 3+j << " " << 9+j << " " << 4+j << " " << 8+j << " " << 6+j <<" " << 12+j << " " ;
		}
		vector<int> ans;
		ans.push_back(2+cnt*12);
		ans.push_back(10+cnt*12);
		ans.push_back(3+cnt*12);
		ans.push_back(9+cnt*12);
		ans.push_back(4+cnt*12);
		ans.push_back(8+cnt*12);
		ans.push_back(6+cnt*12);
		ans.push_back(12+cnt*12);
		for(int i=0;i<q;i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		return 0;
	}
	else{
		int cnt=n/8;
		int q=n%8;
		for(int i=0;i<cnt;i++){
			int j=12*i;
			cout << 6+j << " " << 2+j << " " << 10+j << " " << 3+j << " " << 9+j << " " << 4+j << " " << 8+j <<" " << 12+j << " " ;
		}
		vector<int> ans;
		ans.push_back(6+cnt*12);
		ans.push_back(2+cnt*12);
		ans.push_back(10+cnt*12);
		ans.push_back(3+cnt*12);
		ans.push_back(9+cnt*12);
		ans.push_back(4+cnt*12);
		ans.push_back(8+cnt*12);
		ans.push_back(12+cnt*12);
		for(int i=0;i<q;i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		return 0;
	}
}