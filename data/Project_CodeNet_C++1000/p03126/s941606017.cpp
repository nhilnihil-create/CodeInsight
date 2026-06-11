#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int n ,m ;
    cin >> n;
    cin >> m;
    int a;
    int b;
    int f[m];

    for(int i = 0; i < m; i++){
        f[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            f[b-1] ++;
        }
    }

    int cnt = 0;

    for(int i = 0; i < m; i++){
        if(f[i] == n){
            cnt++;
        }
    }

    cout << cnt << endl;
}