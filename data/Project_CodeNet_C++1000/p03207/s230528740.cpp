#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i = (s);i<(int)(n);i++)

int main(){
    int n;
    cin >> n;
    int sum = 0;
    int k[n];
    rep(i,n){
        cin >> k[i];
        sum += k[i];
    }
    sort(k,k+n);
    int a = k[n-1];
    cout << sum - a/2<< endl;
}