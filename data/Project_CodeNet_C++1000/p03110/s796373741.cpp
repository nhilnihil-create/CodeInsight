/*
      author  : nishi5451
      created : 14.08.2020 23:41:09
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    long double sum=0;
    int n;
    cin >> n;
    rep(i,n){
        long double x;
        string s;
        cin >> x >> s;
        if(s=="JPY"){
            sum += x;
        } 
        else{
            sum += x*380000.0;
        }
    }
    printf("%.12llf\n",sum);
    return 0;
}