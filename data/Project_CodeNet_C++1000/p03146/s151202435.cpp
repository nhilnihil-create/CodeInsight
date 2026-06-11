#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

int main(){
    int n;
    cin >> n;
    map<int, int> m;

    m[n]++;
    int count=1;
    while(1){
        if(n&1){
            n = (3*n)+1;
        }
        else{
            n = n/2;
        }

        m[n]++;
        count++;

        if(m[n] == 2){
            cout << count;
            return 0;
        }
    }
}