#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    long long sum_a = 0, sum_b = 0;

    for(long long i = 0; i < n; i++){
        cin >> a[i];
        sum_a += a[i];
    }
    for(long long i = 0; i < n; i++){
        cin >> b[i];
        sum_b += b[i];
    }

    if(sum_b < sum_a){
        printf("No\n");
        return 0;
    }
    
    long long operation = sum_b - sum_a;

    long long count1 = 0;
    long long count2 = 0;
    for(long long i = 0; i < n; i++){
        if(a[i] < b[i]){
            count1 += (b[i] - a[i])/2;
        }
        else if(a[i] > b[i]){
            count2 += a[i] - b[i];
        }
    }

    if(count1 >= count2){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}