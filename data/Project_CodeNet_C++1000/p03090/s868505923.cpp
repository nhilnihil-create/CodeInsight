#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    if(n%2 == 0){
        cout << n*(n-2)/2 << endl;
        for(int i = 1; i <= n-1; i++){
            for(int j = i+1; j <= n; j++){
                if(i+j == n+1) continue;
                cout << i << " " << j << endl;
            }
        }
    }  
    else{
        cout << (n-1)*(n-1)/2 << endl;
        for(int i = 1; i <= n-1; i++){
            for(int j = i+1; j <= n; j++){
                if(i+j == n) continue;
                cout << i << " " << j << endl;
            }
        }
    }  
}