#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000;

using ll = long long;
using namespace std;

int digits_sum(int n){
    int sum=0;
    while(n>0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int main(){
    int n;
    cin >> n;
    int b, d_sum, min_sum=INF;
    for(int a=1; a<n; a++){
        b = n-a;
        d_sum = digits_sum(a)+ digits_sum(b);
        if(d_sum<min_sum) min_sum = d_sum;
    }
    cout << min_sum << endl;
}