#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mygcd(int a, int b){
    if(a < b){
        int tmp = b;
        b = a;
        a = tmp;
    }

    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int n, x0;
    cin >> n >> x0;

    vector<int> x(n+1);
    for(int i = 0; i < n; i++) cin >> x[i];
    x[n] = x0;
    sort(x.begin(), x.end());
    for(int i = 1; i <= n; i++) x[i] -= x[0];

    for(int i = 2; i <= n; i++){
        x[i] = mygcd(x[i], x[i-1]);
    }
    cout << x[n] << endl;
    return 0;
}