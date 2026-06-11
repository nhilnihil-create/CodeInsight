#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int a[n];
    //全て奇数の時をカウント   
    int cnt = 1;
    for(int i = 0; i < n; i++ ){
        cin  >> a[i];
        if(a[i] % 2 == 0){
            cnt *= 2;
        }else{
            cnt *= 1;
        }
    }
    cout << pow(3,n) - cnt << endl;
    return 0;
}
