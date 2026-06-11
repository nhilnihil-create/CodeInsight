#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long> a_sum(n+1, 0);

    for(long long i = 0; i < n; i++){
        a_sum[i+1] = a[i] + a_sum[i];
    }

    map<long long, long long> T;
    for(long long i = 0; i <= n; i++){
        if(T.find(a_sum[i]) == T.end()){
            T[a_sum[i]] = 1;
        }
        else{
            T[a_sum[i]]++;
        }
    }

    map<long long, long long>::iterator it;
    long long count = 0;
    for(it = T.begin(); it != T.end(); it++){
        if(it->second >= 2){
            count += it->second*(it->second-1)/2;
        }
    }

    cout << count << endl;
    return 0;
}