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
    int a[n];
    rep(i,n)cin >> a[i];
    sort(a,a+n);
    int k = a[n-1];
    int sum = 0;
    rep(j,n) sum += a[j];
    if(sum - k > k)cout << "Yes" <<  endl;
    else cout << "No" << endl;
}