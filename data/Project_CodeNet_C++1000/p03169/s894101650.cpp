#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define db double

db dp[301][301][301];

db solve(int n, int x, int y, int z){
	if(x==0 && y == 0 && z == 0){
		return dp[0][0][0] = 0.0;
	}
	if(dp[x][y][z]==-1){
		db c = ((db)n)/(x+y+z), a1 = ((db)x)/n, b1 = ((db)y)/n,c1 = ((db)z)/n, res = 0.0;
		if(x){
			res += c*a1*solve(n, x-1, y, z);
		}
		if(y){
			res += c*b1*solve(n, x+1, y-1, z);
		}
		if(z){
			res += c*c1*solve(n, x, y+1, z-1);
		}
		return dp[x][y][z] = c + res;
	}
	else{
		return dp[x][y][z];
	}
}

void test(int n, int one, int two, int three){
	db answer = solve(n, one, two, three);
	cout << setprecision(15) << answer << endl;
}

int main(){
	for(int i = 0; i < 301; i++){
		for(int j = 0; j < 301; j++){
			for(int k = 0; k < 301; k++){
				dp[i][j][k] = -1;
			}
		}
	}
	int n, temp, one = 0, two = 0, three = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp==1){
			one++;
		}
		else if(temp==2){
			two++;
		}
		else{
			three++;
		}
	}
	test(n,one, two, three);
	return 0;
}