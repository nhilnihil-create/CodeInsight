#include<bits/stdc++.h>
using namespace std; //std::の省略のため
using ll = long long;

int SUM(int n){
    int sum = 0;
    while(n>0){
        sum += n%10;
        n /= 10;
    }

    return sum;
}

int main(){
    int a,b,n;

    cin >> n >> a >> b;

    int sum = 0;
    int num;

    for(int i = 1; i <= n; i++){
        num = SUM(i);
        if(a <= num && num <= b) sum += i;
    }

    cout << sum << endl;
}