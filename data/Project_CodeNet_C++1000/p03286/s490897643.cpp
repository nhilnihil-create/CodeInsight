#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    if(N == 0){
        cout << N << endl;
        return 0;
    }
    string s;
    while(N != 1){
        if(N > 0){
            if(N % -2 == 0){
                s += '0';
                N /= -2;
            }
            else{
                s += '1';
                N = (N - 1) / -2;
            }
        }
        else{
            if(N % -2 == 0){
                s += '0';
                N /= -2;
            }
            else{
                s+= '1';
                N = N / -2 + 1;
            }
        }
    }
    s += '1';
    reverse(s.begin(), s.end());
    cout << s << endl;
}