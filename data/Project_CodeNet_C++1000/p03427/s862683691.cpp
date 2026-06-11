#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string n;
    cin >> n;

    long long length = n.size();

    string q;

    for(int i = 0; i < length-1; i++){
        q += '9';
    }

    long long maxv = 9*(length-1);

    long long  N = stoll(n);
    for(int j = 1; j <= 9; j++){
        string p;
        char m = j + '0';
        p = m + q;
        long long x = stoll(p);

        if(x <= N){
            maxv = max(maxv, 9*(length-1)+j);
        }
    }
    cout << maxv << endl;

    return 0;
}