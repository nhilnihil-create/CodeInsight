#include<iostream>
#include <queue>
#include <limits>
using namespace std;
int N;
long long X,x[200001], sum[200001];


long long mult(long long a, long long b){
    if (a*b/a!=b){
        return numeric_limits<long long>::max();
    }else{
        return a*b;
    }
}

long long add(long long a, long long b){
    if (a+b-a!=b){
        return numeric_limits<long long>::max();
    }else{
        return a+b;
    }
}

int main(void){
    // cout << numeric_limits<long long>::max() + numeric_limits<long long>::max() << endl;
    cin >> N >> X;

    unsigned long long sum_s = 0;
    for (int i=1;i<=N;i++){
        cin >> x[i];
        sum_s += x[i];
        sum[i] = sum_s;
    }
    sum[0] = 0;
    long long ans = ~ans;
    for (int i=1;i<=N;i++){
        unsigned long long temp = 0;

        int total = 1;
        int j;
        unsigned long long seg_sum;
        for (j=N;j>=i;j-=i){
            seg_sum = sum[j] - sum[j-i];
            if (total==1){
                temp += add(mult(seg_sum, 5), mult(2*i, X));
            }else{
                temp += add(mult(seg_sum, 2*total+1), mult(X, i));
            }
            total++;
        }

        if (j>0){
            seg_sum = sum[j];
            temp += add(mult(seg_sum, 2*total+1), mult(X, j));
        }
        if (temp < ans || ans==-1){
            ans = temp;
        }
    }

    cout << ans << endl;
}
