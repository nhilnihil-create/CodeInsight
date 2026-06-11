
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int keta(int t){
    int g, sum1;
    sum1 = 0;
    while (t > 0){
        g = t % 10;
        t = t / 10;
        sum1 += g;
    }
    return sum1;
    
}



int main(){
    int n, a, b, sum;
    cin >> n >> a >> b;
    sum = 0;
    for (int x = 1; x <= n; x ++){
        if (keta(x) <= b && keta(x) >= a)
            sum += x;
    }
    cout << sum << endl;
    
}