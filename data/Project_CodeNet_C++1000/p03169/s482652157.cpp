#include <bits/stdc++.h>
using namespace std;
/*
given array of ai (1 <= ai <= 3), on each operation, choose a random ai to eat, 
find the expected no. of operations to eat all ai.

3
1 1 1
geometric expectation
P(eat first) = 1 => E(eat first) = 1
P(eat second) = (2/3) => E(eat second) = 3/2 
P(eat third) = 1/3 => E(eat third) = 3 

1 + 3/2 + 3 = 5.5

dp[1] = no. of ones
dp[2] = no. of twos
dp[3] = no. of threes

dp[ones-1][twos][threes] += dp[ones][twos][threes] * ones/(ones+twos+threes)
dp[ones+1][twos-1][threes] += dp[ones][twos][threes] * twos/(ones+twos+threes)
dp[ones][twos+1][threes-1] += dp[ones][twos][threes] * threes/(ones+twos+threes)

*/

const int nax = 305;
double p[nax][nax][nax];
double ev[nax][nax][nax];

int main() {
    /*
    const int INF = 1e9 + 7;
    
    for (int i = 0; i < nax; i++) {
        for (int j = 0; j < nax; j++) {
            for (int k = 0; k < nax; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    */
    
    int n;
    scanf("%d", &n);
    //vector<vector<vector<double>>> p(n+5, vector<vector<double>>(n+5, vector<double>(n+5)));
    //vector<vector<vector<double>>> ev(n+5, vector<vector<double>>(n+5, vector<double>(n+5)));
    //double p[n+5][n+5][n+5];
    //double ev[n+5][n+5][n+5];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                p[i][j][k] = 0;
                ev[i][j][k] = 0;
            }
        }
    }
    
    int ones = 0;
    int twos = 0;
    int threes = 0;
    for (int i = 0; i < n; i++) {
        int dish;
        scanf("%d", &dish);
        if (dish == 1) {
            ones += 1;
        }
        else if (dish == 2) {
            twos += 1;
        }
        else {
            threes += 1;
        }
    }
    
    p[ones][twos][threes] = 1;
    //ev[ones][twos][threes] = 0;
    
    for (int three = n; three >= 0; three--) {
        for (int two = n; two >= 0; two--) {
            for (int one = n; one >= 0; one--) {
                if (one == 0 && two == 0 && three == 0) {
                    continue;
                }
                
                double p_waste = (double) (n - one - two - three) / n;
                double ev_waste = (double) 1 / (1-p_waste);
                //cout << one << " " << two << " " << three << " " << ev_waste << endl;
                //cout << one << " " << two << " " << three << " " << p_waste << endl;
                //cout << ev_waste << endl;
                
                ev[one][two][three] += ev_waste * p[one][two][three];
                //cout << one << " " << two << " " << three << " " << ev[one][two][three] << endl;
                //cout << one << " " << two << " " << three << " " << p[one][two][three] << endl;
                if (one != 0) {
                    double p_go = (double) one / (one + two + three);
                    p[one-1][two][three] += p[one][two][three] * p_go;
                    ev[one-1][two][three] += ev[one][two][three] * p_go;
                }
                if (two != 0) {
                    double p_go = (double) two / (one + two + three);
                    p[one+1][two-1][three] += p[one][two][three] * p_go;
                    ev[one+1][two-1][three] += ev[one][two][three] * p_go;
                }
                if (three != 0) {
                    double p_go = (double) three / (one + two + three);
                    p[one][two+1][three-1] += p[one][two][three] * p_go;    
                    ev[one][two+1][three-1] += ev[one][two][three] * p_go;    
                }
            }
        }
    }
    
	printf("%.20lf", ev[0][0][0]);
	
	
	
	
	return 0;
}