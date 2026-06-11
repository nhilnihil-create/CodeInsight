#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define rep(i,n) for(int i = 0;i < n;i++)

int ch[26];
int main(void){
   string s;cin >> s;
   int n = s.size();
   rep(i,n){
      ch[s[i] - 'a']++;
   }
   
   if(max({ch[0],ch[1],ch[2]}) - min({ch[0],ch[1],ch[2]}) > 1){cout << "NO" << endl;}
   else cout << "YES" << endl;
   
   return 0;
}