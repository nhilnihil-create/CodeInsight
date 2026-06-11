#include <bits/stdc++.h>

using namespace std;

template <class T>
using lim = numeric_limits<T>;

typedef long long ll;
typedef long double ld;

struct Coord{
	ll x;
	ll y;
	
	Coord(){
		x = y = 0;
	}
	
	Coord(ll _x, ll _y){
		x = _x;
		y = _y;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, K;
	cin >> N >> K;
	
	Coord points[N];
	ll x[N];
	ll y[N];
	
	for(int i = 0; i < N; i++){
		cin >> points[i].x >> points[i].y;
		x[i] = points[i].x;
		y[i] = points[i].y;
	}
	
	ll area = lim<ll>::max();
	
	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			for (int k = 0; k < N; k++){
				for (int l = k+1; l < N; l++){
					
					ll leftX = min(x[i],x[j]);
					ll rightX = max(x[i],x[j]);
					ll topY = max(y[k], y[l]);
					ll botY = min(y[k], y[l]);
					
					int counter = 0;
					for (int m = 0; m < N; m++){
						if (points[m].x >= leftX && points[m].x <= rightX && points[m].y >= botY && points[m].y <= topY) counter++;
					}
					
					if (counter >= K) area = min(area, (rightX-leftX)*(topY-botY));
				}
			}
		} 
	}
	
	cout << area << endl;
}
