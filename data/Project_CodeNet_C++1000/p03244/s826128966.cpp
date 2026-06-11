#include <iostream>
#include <cstdio> 
#include <map>
using namespace std;

int main(){
    long long n;
    cin >> n;

    map<long long, long long> even;
    map<long long, long long> odd;
    map<long long, long long> T;

    for(long long i = 0; i < n; i++){
        long long v;
        cin >> v;

        if(T.find(v) == T.end()){
            T[v] = 1;
        }
        else{
            T[v] += 1;
        }

        if(i % 2 == 0){
            if(even.find(v) == even.end()){
                even[v] = 1;
            }
            else{
                even[v] += 1;
            }
        }
        else{
            if(odd.find(v) == odd.end()){
                odd[v] = 1;
            }
            else{
                odd[v] += 1;
            }
        }
    }

    if(T.size() == 1){
        printf("%lld\n", n/2);
        return 0;
    }

    long long count_even = 0, count_odd = 0;

    long long max_even_value = 0;
    long long max_odd_value = 0;
    long long max_even_key = 0;
    long long max_odd_key = 0;
     long long max2_even_value = 0;
    long long max2_odd_value = 0;
    long long max2_even_key = 0;
    long long max2_odd_key = 0;

    map<long long, long long>::iterator it;

    for(it = even.begin(); it != even.end(); it++){
        if(max_even_value < it->second){
            max_even_value = it->second;
            max_even_key = it->first;
        }
    }
    even.erase(max_even_key);
    for(it = even.begin(); it != even.end(); it++){
        if(max2_even_value < it->second){
            max2_even_value = it->second;
            max2_even_key = it->first;
        }
    }
  
    for(it = odd.begin(); it != odd.end(); it++){
        if(max_odd_value < it->second){
            max_odd_value = it->second;
            max_odd_key = it->first;
        }
    }
    odd.erase(max_odd_key);
    for(it = odd.begin(); it != odd.end(); it++){
        if(max2_odd_value < it->second){
            max2_odd_value = it->second;
            max2_odd_key = it->first;
        }
    }


    if(max_odd_key != max_even_key){
        cout << n - max_odd_value - max_even_value << endl;
        return 0;
    }

    cout << min(n - max_odd_value - max2_even_value, n - max2_odd_value - max_even_value) << endl;

    return 0;
}