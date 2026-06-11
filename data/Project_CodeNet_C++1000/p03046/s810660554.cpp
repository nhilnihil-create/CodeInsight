#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<cstdio>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)
#define P pair<long int, long int>


int main(){
    int m, k;
    cin >> m >> k;
    int n = (1 << (m+1));
    if (k >= (1 << m)){
        cout << -1 << endl;
    }else if (m == 1){
        if (k == 0){
            cout << "0 0 1 1" << endl;
        }else{
            cout << -1 << endl;
        }
        
    }else{
        int a[n];
        int num = 0;
        for (int i = 0; i < k; i++){
            a[i] = i;
        }
        for (int i = k; i < n / 2 - 1; i++){
            a[i] = i + 1;
        }
        a[n/2-1] = k;
        a[n-1] = k;
        for (int i = 0; i < k; i++){
            a[n-2-i] = i;
        }
        for (int i = k; i < n / 2 - 1; i++){
            a[n-2-i] = i + 1;
        }

        rep(i, n) cout << a[i] << " ";
        cout << endl;
    }

}
