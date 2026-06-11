#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

struct node{
	int x;
	int y;
	int h;
};

using namespace std;
typedef long long int ll;

int main()
{
	int n;
	cin>>n;
	vector<node> points(n);
	int pivot = 0;
	for(int i = 0; i < n; i++){
		cin>>points[i].x>>points[i].y>>points[i].h;
		if( points[i].h > 0) pivot = i;
	}
	//cout<<"pivot"<<pivot<<endl;
	for(int x = 0; x <= 100; x++){
		for(int y = 0; y <= 100; y++){
			int H = points[pivot].h + abs(x-points[pivot].x) + abs(y-points[pivot].y);
			bool ans = true;
			for(int i = 0; i < n; i++){
				if( points[i].h != max(H - abs(x - points[i].x) - abs(y - points[i].y),0)){
					ans = false;
					break;
				}
			}
			if(ans == true){
				cout<<x<<" "<<y<<" "<<H<<endl;
				return 0;
			}
		}
	}
	return 0;
}
