#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    long long n;
    cin >> n;

    map<long long, long long> T;

    for(long long i = 0; i < n; i++){
        long long a;
        cin >> a;

        if(T.find(a) == T.end()){
            T[a] = 1;
        }
        else{
            T[a] += 1;
        }
    }

    map<long long, long long>::iterator it;

    long long count = 0;
    for(it = T.begin(); it != T.end(); it++){
        //printf("it->first %lld it->second %lld\n", it->first, it->second);

        if(it->first == it-> second){
            continue;
        }

        if(it->first < it->second){
            count += it->second - it->first;
        }
        else if(it->first > it->second){
            count += it->second;
        }
    }

    cout << count << endl;

    return 0;

}