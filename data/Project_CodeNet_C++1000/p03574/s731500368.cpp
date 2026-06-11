#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#include <cstdlib>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
   int h, w; cin >> h >> w;
   char s[h][w];
   char ans[h][w];

   rep(i, h){
       rep(j, w) cin >> s[i][j];
   }
   
   rep(i, h){
       rep(j, w){
           ans[i][j] = s[i][j];
       }
   }

   int sx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
   int sy[8] = {0, 1, -1, 1, -1, 0, 1, -1};

   rep(i, h){
       rep(j, w){
           int cnt = 0;
           if(s[i][j]=='#'){
               cout << '#';
               continue;
           };
           rep(k, 8){
               if(i+sy[k]<0||i+sy[k]>=h||j+sx[k]<0||j+sx[k]>=w){
                   continue;
               }
               else if(s[i+sy[k]][j+sx[k]]=='#') cnt++;
           }
           cout << cnt;
       }
       cout << endl;
   }
}