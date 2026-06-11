#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = 1000000;
int main(){
	int N;
	cin >> N;
	P red[N], blue[N];
	int x, y;
	for(int i=0;i<N;i++){
		cin >> x >> y;
		red[i] = make_pair(x, y);
	}
	for(int i=0;i<N;i++){
		cin >> x >> y;
		blue[i] = make_pair(x, y);
	}

	sort(red, red+N);
	sort(blue, blue+N);

	bool connected[N];
	for(int i=0;i<N;i++) connected[i] = false;

	int ans = 0;
	int candi;

	for(int i=0;i<N;i++){
		bool flag = false;
		for(int k=0;k<N;k++){
			if(red[k].first < blue[i].first && red[k].second < blue[i].second 
				&& !connected[k]){
				candi = k;
				flag = true;
				break;
			}
		}
		if(flag){
			int k = 0;
			while(k<N){
				if(red[k].first < blue[i].first && red[k].second < blue[i].second 
					&& red[candi].second < red[k].second && !connected[k]){
					candi = k;
				}
				k++;
			}
			ans++;
			connected[candi] = true;
		}		
	}
	cout << ans <<endl;
  	return 0;
}






