#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    int x,now,beki;
    cin >> x;
    beki = 2;
    int id = 2;
    now = 2;
    int ans = 1;
    while(id < x){
       now = id*id;
       beki = id;
       while(now <= x){
          ans = max(ans,now);
          now *= beki; 
       }
       id++;
    }
    cout << ans << endl;
    return 0;

}