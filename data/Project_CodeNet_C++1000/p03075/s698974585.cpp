#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950

int main(){
    vector<int> a (5) ;
    rep(i, 5) {
        cin >> a[i] ;
    }
    int k ;
    cin >> k ;
    bool ans = true ;
    rep(i, 5){
        rep(j, 5){
            if(abs(a[i] - a[j]) > k){
                ans = false ;
            }
        }
    }
    if(ans){
        cout << "Yay!" << endl ;
    }
    else {
        cout << ":(" << endl ; 
    }
}