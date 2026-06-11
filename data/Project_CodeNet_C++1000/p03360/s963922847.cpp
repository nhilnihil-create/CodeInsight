#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int ans = a+b+c;
    int mx = max({a,b,c});
    
    for (int i = 0; i < k;i++){
        mx *= 2;
    }
    cout << ans-max({a,b,c}) +mx << endl;

    

   return 0;

}