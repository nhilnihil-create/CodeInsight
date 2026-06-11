#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,T,hantei=1;
    cin >> n >> T;
    int c[n],t[n];
    int c_save=1000;
    for(int i=0;i<n;i++){
        cin >> c[i] >> t[i];
    }
    for(int i=0;i<n;i++){
        if(T>=t[i] && c_save>=c[i]){
                c_save = c[i];
                hantei = 0;
        }
    }
    if(hantei == 1) cout << "TLE" << endl;
    else cout << c_save << endl;
}