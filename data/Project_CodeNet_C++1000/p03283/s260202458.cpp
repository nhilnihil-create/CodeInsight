#include<bits/stdc++.h>
using namespace std;
int c[505][505];
int main(){
    int n,m,q;
    cin >> n >> m >> q;
    int L,R;
    for(int i=0;i<m;i++){
        cin >> L >> R;
        c[L][R]++;
    }
    for(int j=1;j<n+1;j++){
        for(int i=j;i>1;i--){
            c[i-1][j]+=c[i][j];
        }
    }
    for(int j=n;j>=1;j--){
        for(int i=j;i<n+1;i++){
            c[j][i+1]+=c[j][i];
        }
    }
    for(int i=0;i<q;i++){
        cin >> L >> R;
        cout << c[L][R] << endl;
    }
}