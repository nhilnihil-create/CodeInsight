/*
      author  : nishi5451
      created : 14.08.2020 16:02:32
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    int N = n;
    int sum = 0;
    while(n){
        sum += n%10;
        n/=10;
    }
    if(N%sum==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}