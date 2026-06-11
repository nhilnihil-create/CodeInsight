#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    int n,A,B;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a.at(i);
    A = 0;
    B = 0;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    rep(i,0,n){
        if(i%2==0){
             A += a.at(i);
        }else{
            B += a.at(i);
        }
        
    }
    cout << A-B << endl;
    
}