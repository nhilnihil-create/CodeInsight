#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int M = min(a,b);
    int m = max(0,a+b-n);

    cout << M << " " << m << endl;


    return 0;
}
