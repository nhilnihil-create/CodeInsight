#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
const int INF = 998244353;
bool palin(string S){//Sが回文かどうか
    int M = (S.size()-1)/2 + 1;
    int n = S.size();
    bool flag = true;
 
    for(int i = M;i<n;i++){
        if(S[i] != S[n-i-1]) flag = false;
    }
   return flag;
}

using Graph = vector<vector<int>>;
/*
*/


int main() {
   string s;
   cin >> s;
   ll ans = 0;
   int l = 0;//sの先頭
   int r = s.size()-1;//rの末尾
   while(l<r){
       if(s[l] == s[r]){
          l++;
          r--;
       }
       else if(s[l] == 'x' && s[r] != 'x'){
           l++;
           ans++;
       }
       else if(s[l] != 'x' && s[r] == 'x'){
           r--;
           ans++;
       }
       else if(s[l] != 'x' && s[r] != 'x'){
           ans = -1;
           break;
       }
   }
   cout << ans << endl;
}