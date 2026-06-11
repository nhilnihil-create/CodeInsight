#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; 
    cin >> n;
	vector<pair<int,int>> x(n);
	for(int i=0; i<n; i++){
		int a; 
        cin >> a;
		x[i] = make_pair(a,i);
	}
	sort(x.begin(),x.end());
	int l = x[n/2-1].first;
	int r = x[n/2].first;
	vector<bool> left(n,false);
	for(int i=0; i<n; i++){
		if(i < n/2){
			left[x[i].second] = true;
		}
	}
	for(int i=0; i<n; i++){
		cout << (left[i] ? r : l) << endl;
	}
    return 0;
}