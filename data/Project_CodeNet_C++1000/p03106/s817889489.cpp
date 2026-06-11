/*
      author  : nishi5451
      created : 14.08.2020 23:46:05
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,k;
    cin >> a >> b >> k;
    int i=min(a,b);
    int now=0;
    while(i){
        if(a%i==0 && b%i==0){
            now++;
            if(now == k){
                cout << i << endl;
                return 0;
            }
        } 
        i--;  
    }
    return 0;
}