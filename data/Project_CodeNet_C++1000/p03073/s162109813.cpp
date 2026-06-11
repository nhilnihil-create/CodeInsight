#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s;
    cin >> s;

    string t0, t1;

    for(long long i = 0; i < s.size(); i++){
        if(i % 2 == 0){
            t0.push_back('0');
            t1.push_back('1');
        }
        else{
            t0.push_back('1');
            t1.push_back('0');
        }
    }
    long long count1 = 0, count0 = 0;
    for(long long i = 0; i < s.size(); i++){
        if(t0[i] != s[i]){
            count0++;
        }

        if(t1[i] != s[i]){
            count1++;
        }
    }

    cout << min(count0, count1) << endl;

    return 0;
}