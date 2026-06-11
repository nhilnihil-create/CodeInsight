#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define MAX 1000000007
using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;
    
    int grid[101][101];
    rep(i,100){
        rep(j,100){
            if(i <= 50) grid[i+1][j+1] = 1;
            else grid[i+1][j+1] = 0;
        }
    }

    for(int i=1;i<=50;i+=2){
        for(int j=1;j<=100;j+=2){
            if(a != 1){
                if(i%2 == 0)grid[i][j] = 0;
                else grid[i][j+1] = 0;
                a--;
            }
            if(b != 1){
                if(i%2 == 0)grid[101-i][j] = 1;
                else grid[101-i][j+1] = 1;
                b--;
            }
        }
    }

    cout << 100 << " " << 100 << endl;
    rep(i,100){
        rep(j,100){
            if(grid[i+1][j+1]) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }

	return 0;
}
