#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<functional>
using namespace std;
typedef	long long int ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if(a+b-1 > n || n > a*b){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < b; i++){
        cout << b-i << ' ';
    }
    if(a==1) {
        cout << endl;
        return 0;
    }
    int q = (n-b)/(a-1);
    for(int i = q; i >= 1; i--){
        for(int j = 0; j < a-1;j++){
            cout << n-(q-i)*(a-1)-(a-2)+j << ' ';
        }
    }
    for(int i = b+1; i <= n-q*(a-1); i++){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}