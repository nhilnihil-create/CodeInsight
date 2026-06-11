#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    int n,c,count;
    c=0;
    count=0;
    cin >> n;
    for (int i=1; i<n+1; i=i+2){
        for (int j=1; j<i+1; j=j+2){
            if (i%j==0){
                c=c+1;
            }
        }
        if (c==8){
                count=count+1;
            }
        c=0;
    }
    cout << count;
}