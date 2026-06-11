#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int f(int n){
    int sum =0;
    while(n!=0){
        sum += n%10;
        n /=10;
    }
    return sum;
}

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int N;
    cin >> N;
    int j,max=-1;
    for(int i =1 ;i<N;i++){
        j = N-i;
        int i_sum = f(i);
        int j_sum = f(j);
        if(max == -1 || i_sum + j_sum < max)
            max = i_sum + j_sum;
    }
    cout<<max<<endl;
}