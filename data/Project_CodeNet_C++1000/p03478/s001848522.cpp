#include <bits/stdc++.h>
using namespace std;
int getting_digits_sum(int number){
    int sum =0;
    while(number > 0){
       sum += number%10;
       number /= 10;
    }
    return sum;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int sum = 0;
    for(int i=1; i<=n; i++){
        if(getting_digits_sum(i) >= a && getting_digits_sum(i) <= b) sum += i;
    }
    cout << sum << endl;
}