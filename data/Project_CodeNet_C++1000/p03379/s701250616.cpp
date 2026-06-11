#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    long long median;

    cin >> n;

    median = n/2;

    long long x;
    vector <long long> v;
    vector <long long> result;

    for(long long i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    vector <long long> v_copy;

    long long median_v;

     v_copy = v;
     sort(v_copy.begin(), v_copy.end());

    for(long long i = 0; i < v.size(); i++){


        x = v[i];
       
        median_v = v_copy[median-1];
        if(x <= median_v){
            result.push_back(v_copy[median]);
        }
        else{
            result.push_back(v_copy[median-1]);
        }
    }

    for(long long i = 0; i < result.size(); i++){
        printf("%lld\n", result[i]);
    }
    

}