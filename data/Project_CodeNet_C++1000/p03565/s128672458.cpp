#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
   string s, t; cin >> s >> t;
   vector<string> ans;
   int l = s.size()-t.size()+1; //移動できる範囲

   for(int i = 0; i < max(0, l); i++) {
       string tmp = s;
       for (int j = 0; j < t.length(); j++) {
           if(i+j>s.size()-1) break; //インデックスをはみ出したら中止
           if(tmp[i+j]=='?' || tmp[i+j]==t[j]) tmp[i+j] = t[j]; //s[i+j]=='?' と s[i+j] == t[j] は t[j]にする 
           else break; // それ以外はダメ
           if(j==t.length()-1) {
               for(int k = 0; k < tmp.length(); k++) {
                   if(tmp[k] == '?') tmp[k] = 'a';//余ったs[i+j]=='?'を'a'にする
               }
               ans.push_back(tmp);
           }
       }
   }
   sort(ans.begin(), ans.end());
   cout << (ans.size() > 0 ? ans[0] : "UNRESTORABLE" ) << endl;
   return 0;
}

/*

テストケース１
?????
z

正解：aaaaz　（間違い：zaaaa）
*/