#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
using namespace std;
int N, Q;
string s;
vector<char> t(200000),d(200000);
int tou(int x){
	int ans=x;
	for(int i=0;i<Q;i++){
		if(ans < 0 || ans >= N)break;
		if(t[i] == s[ans]){
			if(d[i] == 'L')ans--;
			else ans++;
		}
	}
	return ans;
}
int main(){
	cin >> N >> Q;
	cin >> s;
	for(int i=0;i<Q;i++){
		cin >> t[i] >> d[i];
	}
	int mid1 = N / 2;
	int last1 = N - 1;
	int first1 = 0;
	while(last1 - first1 > 0){
		if(tou(mid1) < 0){
			first1 = mid1 + 1;
		}
		else{
			last1 = mid1 - 1;
		}
		mid1 = (last1 - first1) / 2 + first1;
	}
	int mid2 = N / 2;
	int last2 = N - 1;
	int first2 = 0;
	while(last2 - first2 > 0){
		if(tou(mid2) >= N){
			last2 = mid2 - 1;
		}
		else{
			first2 = mid2 + 1;
		}
		mid2 = (last2 - first2) / 2 + first2;
	}
	if(tou(mid1) < 0)mid1++;
	if(tou(mid2) >= N)mid2--;
	cout << mid2 - mid1 + 1 << endl;
}