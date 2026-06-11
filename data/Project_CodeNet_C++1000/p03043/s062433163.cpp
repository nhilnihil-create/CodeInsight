#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int mylog2(int a, int k){
    int i = 0;
    int pow = a;
    for(; pow < k; pow *= 2, i++);
    return i;
}

int main(){
    int n, k;
    cin >> n >> k;

    double ans = 0;
    for(int i = n; i >= 1; i--){
        //cout << i << endl;
        int rep = mylog2(i, k);
        ans += (1/pow(2, rep));
        
    }

    ans /= n;
    printf("%.10lf\n", ans);
}