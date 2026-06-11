#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int ans = 0;

    while(true){
        if(ans * ans > N){
            break;
        }
        ans++;
    }    
    cout << (ans - 1) * (ans - 1) << endl;
} 