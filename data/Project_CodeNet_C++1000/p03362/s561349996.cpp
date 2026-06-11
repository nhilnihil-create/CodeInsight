#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    vector<int> ary;
    for(int i = 2; i <= 55555; i++){
        bool flag = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag && i % 5 == 1) ary.push_back(i);
    }
    int n;
    cin >> n;
    rep(i, n){
        if(i) printf(" ");
        printf("%d", ary[i]);
    }
    printf("\n");
}