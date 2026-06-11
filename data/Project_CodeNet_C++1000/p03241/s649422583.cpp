#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

//約数列挙
vector<long long> calc_divisor(long long n){
    vector<long long> res;
    for(long long i = 1LL; i*i <= n;i++){
        if(n % i == 0){
            res.push_back(i);
            long long j = n/i;
            if(j != i)res.push_back(j);
        }
    }
    sort(res.begin(),res.end());
    return res;
}




int main(){
    long long N,M;
    cin>> N >> M;
    vector<long long> div = calc_divisor(M);
    
    //Mの約数dであって、d*N <= M となる最大の d を求める。
    long long res = 1;
    for(auto d:div){
        if(d*N <= M)res = max(res,d);
    }
    cout << res << endl;
    
}