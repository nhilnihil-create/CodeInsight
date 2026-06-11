#include<iostream>
#include<algorithm>
using namespace std;

struct info{
	long long int x, y, z;
};

long long int INF = 1e18;
int n, m;
int st[] = {0, 0, 0};
const int N = 1e3+10;
info v[N];

long long int cost(){
	long long int s1 = 0;
	long long int s2 = 0;
	long long int s3 = 0;
	for(int i=0; i < m; i++){
		s1 += v[i].x;
		s2 += v[i].y;
		s3 += v[i].z;
	}
	return abs(s1) + abs(s2) + abs(s3);
}

long long int value(info tmp){
	long long int ans = 0;
	long long int aux[] = {tmp.x, tmp.y, tmp.z};
	for(int i=0; i < 3; i++){
		if(st[i]) ans += aux[i];
		else ans -= aux[i];
	}
	return ans;
}

bool cmp_p(info i1, info i2){
	long long int v1 = value(i1);
	long long int v2 = value(i2);
	return v1 > v2;
}



int main(){
	cin >> n >> m;
	for(int i=0; i < n; i++)
		cin >> v[i].x >> v[i].y >> v[i].z;
	

	long long int ans = -INF;
	for(int i=0; i <= 1; i++){
		for(int j=0; j <= 1; j++){
			for(int k=0; k <= 1; k++){
				st[0] = i;
				st[1] = j; 
				st[2] = k;
				sort(v, v+n, cmp_p);
				ans = max(ans, cost());
			}
		}
	}
	cout << ans << endl;
}