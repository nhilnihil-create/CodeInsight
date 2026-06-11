#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
    int n0, n1;
    cin >> n0 >> n1;
    if(n0%2 != 0 && n1%2 != 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}