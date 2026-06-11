#include<iostream>
using namespace std;
int n, i, j, a, b, x;
int v[5005];
long long d[5005][5005], s[5005][5005];
int main(){
    cin>> n >> a >> b;
    for(i = 1; i <= n; i++){
        cin>> x;
        v[x] = i;
    }
    for(i = 1; i <= n; i++){
        for(j = 0; j <= n + 1; j++){
            if(j <= v[i]){
                d[i][j] = s[i - 1][j] + b;
            }
            else{
                d[i][j] = s[i - 1][j] + a;
            }
            if(j == v[i]){
                d[i][j] = min(d[i][j], s[i - 1][j - 1]);
            }
            s[i][j] = d[i][j];
            if(j != 0){
                s[i][j] = min(s[i][j], s[i][j - 1]);
            }
        }
    }
    cout<< s[n][n + 1];
}
