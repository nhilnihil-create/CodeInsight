#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const int MAXN = 301;

int N;
double lgN;
double expected[MAXN][MAXN][MAXN];

double solve(int x, int y, int z){
		if(x < 0 || y < 0 || z < 0) return 0;
		if(expected[x][y][z] != -1) return expected[x][y][z];
		if(!x && !y && !z) return expected[0][0][0] = 0;
		int T = x+y+z;
		double lT = log(T);
		//expected to remove non-zero = N/T
		double expect = exp(lgN - lT);
		//calc probabilities for 3,2,1 (i.e. solve_next*P(i)/P(non))
		expect += exp(log(x) - lT + log(solve(x-1, y+1, z)));
		expect += exp(log(y) - lT + log(solve(x, y-1, z+1)));
		expect += exp(log(z) - lT + log(solve(x, y, z-1)));
		return expected[x][y][z] = expect;
}

int main(){
		for(int i = 0; i < MAXN; i++){
				for(int j = 0; j < MAXN; j++){
						for(int k = 0; k < MAXN; k++){
								expected[i][j][k] = -1;
						}
				}
		}
		cin >> N;
		lgN = log(N);
		int c3 = 0, c2 = 0, c1 = 0;
		for(int i = 0; i < N; i++){
				int x;
				cin >> x;
				if(x == 3) c3++;
				else if(x == 2) c2++;
				else if(x == 1) c1++;
		}
		cout << setprecision(15) << solve(c3,c2,c1) << endl;
		return 0;
}
