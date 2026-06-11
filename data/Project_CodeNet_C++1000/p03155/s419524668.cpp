#include <bits/stdc++.h>
using namespace std;

int choice(int n,int k){
    if(n == k){
        return 1;
    }
    if(k == 1){
        return n;
    }
    return choice(n-1,k-1) + choice(n-1,k);
}

int main(){  
    int n ,h ,w;
    cin >> n >> h >> w;
    cout << (n-h+1) * (n-w+1) << endl;
}