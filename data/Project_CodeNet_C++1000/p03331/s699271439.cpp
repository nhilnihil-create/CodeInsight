#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); ++i)
using namespace std;
using ll = long long;

int SumOfEveryone(int n){
    int sum = 0;
    while(n>0){
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    int min_sum = 99999;
        for(int i=1; i < N; ++i){
            min_sum = min(min_sum, SumOfEveryone(i) + SumOfEveryone(N-i));
        }
    cout << min_sum << endl;
    }