#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int x;
    cin >> x;
    vector<bool> expo(x+1);
    expo[1] = 1;
    for(int i = 2;i <= x;i++){
        int v = i*i;
        while(v <= x){
            expo[v] = 1;
            v *= i;
        }
    }
    for(int i = x;i >= 1;i--){
        if(expo[i]){cout << i;
        return 0;}
    }
}
