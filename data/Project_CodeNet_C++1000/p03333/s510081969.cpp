#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;
vector<pair<long long,long long>> l1,l2,r1,r2,y;
bool used[100010];
long long ans1=0,ans2=0,i,n,l,r;
int main(){
	cin >> n;
	for(i=0;i<n;i++){
		cin >> l >> r;
		y.push_back(make_pair(l,r));
		l1.push_back(make_pair(l,i));
		l2.push_back(make_pair(l,i));
		r1.push_back(make_pair(r,i));
		r2.push_back(make_pair(r,i));
		used[i] = true;
	}
	sort(l1.begin(),l1.end());
	sort(l2.begin(),l2.end());
	sort(r1.rbegin(),r1.rend());
	sort(r2.rbegin(),r2.rend());
	
	int x = 0,k=0;
	while(k<n){
		if(k%2==0){
			if(used[l1.back().second]){
				k++;
				if(y[l1.back().second].first <= x && x <= y[l1.back().second].second){
					ans1 += 0;
				}else{
					ans1 += abs(l1[l1.size()-1].first-x);
					x = l1[l1.size()-1].first;
					used[l1[l1.size()-1].second] = false;
				}
			}else{
				l1.pop_back();
			}
		}else{
			if(used[r1.back().second]){
				k++;
				if(y[r1.back().second].first <= x && x <= y[r1.back().second].second){
					ans1 += 0;
				}else{
					ans1 += abs(r1.back().first-x);
					x = r1.back().first;
					used[r1.back().second] = false;
				}
			}else{
				r1.pop_back();
			}
		}
	}
	ans1 += abs(x);
	for(i=0;i<n;i++){
		used[i] = true;
	}
	x = 0; k = 0;
	while(k<n){
		if(k%2==0){
			if(used[r2.back().second]){
				k++;
				if(y[r2.back().second].first <= x && x <= y[r2.back().second].second){
					ans2 += 0;
				}else{
					ans2 += abs(r2[r2.size()-1].first-x);
					x = r2.back().first;
					used[r2.back().second] = false;
				}
			}else{
				r2.pop_back();
			}
		}else{
			if(used[l2.back().second]){
				k++;
				if(y[l2.back().second].first <= x && x <= y[l2.back().second].second){
					ans2 += 0;
				}else{
					ans2 += abs(l2.back().first-x);
					x = l2.back().first;
					used[l2.back().second] = false;
				}
			}else{
				l2.pop_back();
			}
		}
	}
	ans2 += abs(x);
	cout << max(ans1,ans2) << endl;
}