#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    long long N;
    cin >> N;
    string s;
    long long n;
    if(N % 2 == 0){
        s = '0';
        n = 0;
    }
    else{
        s = '1';
        n =  1;
        }
    long long t = 4;
    long long pow = -2;
    while(true){
        if(n == N) break;
        s += abs(((N % t + t) % t - (t + n) % t)) / (t / 2) + '0';
        n += (s[s.size() - 1] - '0') * pow;
        pow *= -2;
        t *= 2;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}