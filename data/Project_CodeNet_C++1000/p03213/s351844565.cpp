#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<cmath>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int a[101];
int ans;


void fact(int x){
    for (int i = 2; i <= x; i++){
        while (x % i == 0){
            a[i]++;
            x /= i;
        }
    }
}

void dfs(int* x, int m, int num){
    if (m == 3){
        rep(i, 2) if(x[i] == x[i+1] && x[i] >= 2) return;
        if(x[2] == 1) return;
        else if (x[1] == 1){
            if (a[x[2]] >= 74){
                ans++;
            }
        }else if(x[0] == 1){
            if (a[x[1]] >= 4 && a[x[2]] >= 14){
                ans++;
            }
            if (a[x[1]] >= 14 && a[x[2]] >= 4){
                ans++;
            }
            if (a[x[1]] >= 2 && a[x[2]] >= 24){
                ans++;
            }
            if (a[x[1]] >= 24 && a[x[2]] >= 2){
                ans++;
            }        
        }else{
            if (a[x[0]] >= 2 && a[x[1]] >= 4 && a[x[2]] >= 4){
                ans++;
            }
            if (a[x[0]] >= 4 && a[x[1]] >= 2 && a[x[2]] >= 4){
                ans++;
            } 
            if (a[x[0]] >= 4 && a[x[1]] >= 4 && a[x[2]] >= 2){
                ans++;
            }
        }        
        return;
    }
    
    int b[3];
    rep(i, 3) b[i] = x[i];
    for (int i = num; i <= 100; i++){
        b[m] = i;
        dfs(b, m + 1, i);
    }
    

}

int main(){
    int n;
    cin >> n;
    rep(i, n-1) fact(i+2);
    int x[3];
    dfs(x, 0, 1);
    cout << ans << endl;
}

