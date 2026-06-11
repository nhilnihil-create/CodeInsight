#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long n, h;
    cin >> n >> h;

    vector<long long> a(n), b(n);

    long long a_max = 0;
    for(long long i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        a_max = max(a_max, a[i]);
    }

    vector<long long> throw_sord;

    for(long long i = 0; i < n; i++){
        if(b[i] >= a_max){
            throw_sord.push_back(b[i]);
        }
    }

    sort(throw_sord.begin(), throw_sord.end(), greater<long long>());

    long long count = 0;
    long long j = 0;
    while(j < throw_sord.size()){
        if(h <= 0){
            break;
        }
        h -= throw_sord[j];
        count++;
        j++;
    }
    
    if(h <= 0){
        printf("%lld\n", count);
    }
    else{
        count += (h + a_max - 1)/a_max;
        printf("%lld\n", count);
    }

    return 0;
}