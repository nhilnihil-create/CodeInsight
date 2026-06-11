#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<deque>
#include<cmath>
#include<stack>
#include<string.h>
#include <iomanip>
#define rep(i,n) for(int i = 0;i<n;i++)
#define _GLIBCXX_DEBUG
using ll = long long; 
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
	int n;
	cin >>n ;
	vector<int>x(n),y(n),h(n);
	rep(i,n) {
		cin >> x[i] >> y[i] >> h[i];
	}
	for(int Cx = 0;Cx<=100;Cx++) {
		for(int Cy = 0;Cy<=100;Cy++) {
			int H = -1;
			for(int i = 0;i<n;i++) {
				if(h[i]>0) {
					int tmp = h[i]+abs(Cx-x[i])+abs(Cy-y[i]);
					
					if(H==-1) {
						H = tmp;
					} else {
						if(H != tmp) {
							H = -2;
							break;
						}
					}
				}
			}
			
			if(H==-2) continue;
			for(int i = 0;i<n;i++) {
				if(h[i]==0) {
					int dist = abs(Cx-x[i])+abs(Cy-y[i]);
					if(H>dist) {
						H = -2;
						break;
					}
				}
			}
			if(H == -2) continue;
			cout << Cx << " " << Cy << " " << H << endl;
			return 0;
		}
	}
}