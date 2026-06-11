#include<iostream>
#include<vector>

using namespace std;
int a[105][15], p[105][15];
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < 10; j++){
        cin >> a[i][j];
    }
    for(int i = 0; i < n; i++)
    for(int j = 0; j < 11; j++){
        cin >> p[i][j];
    }
    long long ans = -(1ll<<32);
    for(int mask = 1; mask < (1ll<<10); mask++){
        long long c1 = 0;
        for(int i = 0; i < n; i++){
            int c2 = 0;
            for(int j = 0; j < 10; j++){
                if(mask & (1<<j) && a[i][j]) c2++;
            }
            c1 += p[i][c2];
        }
        if(ans < c1) ans = c1;
    }
    cout << ans;
}
