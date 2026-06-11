#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int f(int n){
    int sum=0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    int n, _a, _b; cin >> n;
    int min=1e7;
    int ans=0;
    for(int i=1; i < n; i++){
        int j = n-i;
        _a = f(i);
        _b = f(j);
        if(min > _a+_b) min = _a+_b;
    }
    cout << min << endl;
    return 0;
}
