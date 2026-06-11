#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<cmath>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int n;
    cin >> n;
    long int a[34];
    n += pow(2, 35);
    long int now = 0;
    long int t = 1;
    for (long int i = 0; i < 34; i++){
        if (n % (t * 2) != ((t * 2) - now) % (t * 2)){
            a[i] = 1;
        }else{
            a[i] = 0;
        }
        if (i % 2 == 1){
            now += a[i] * t;
        }else{
            now += a[i] * (-t);
        }
        t *= 2;
    }
    bool flag = false;
    for (int i = 33; i >= 0; i--){
        if (a[i] == 1 && !flag){
            cout << a[i];
            flag = true;
            continue;
        }
        if (flag){
            cout << a[i];
        }
    }
    if (flag){
        cout << endl;        
    }else{
        cout << 0 << endl;
    }
    
    

}
