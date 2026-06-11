#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    int ev = 0;
    int od = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];

        if(a[i] % 2 == 0){
            ev++;
        }else{
            od++;
        }
    }

    int ans = 1;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            ans *= 2;
        }
    }

    cout << pow(3, n) - ans << endl;
}