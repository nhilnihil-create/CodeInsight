/*
　　　　　　 ＿＿
　　　　　／＞　　 フ
　　　　　|   _　 _l  
　 　　　／` ミ＿x ノ   Zzz..
　　 　 /　 　 　 |   コード見ちゃだめ！！
　　　 /　 ヽ　　  ﾉ
　 　 │　　|　|  |   
　／￣|　　 |　|  |
　| (￣ヽ＿_ヽ_)_ _)
　＼二つ
*/

#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) reverse((a).begin(),(a).end())
#define REP(i, n) for(int i = 0; i < n; i++)
const int MOD = 1e9+7;
typedef long long ll;


int main(){
    string s;
    cin>>s;
    if(s=="KIHBR"||s=="AKIHBR"||s=="AKIHABR"||s=="AKIHBAR"||s=="AKIHBRA"||
      s=="AKIHABAR"||s=="AKIHABRA"||s=="AKIHBARA"||s=="AKIHABARA"||
      s=="KIHABR"||s=="KIHABAR"||s=="KIHABRA"||s=="KIHABARA"||s=="KIHBAR"||
      s=="KIHBRA"||s=="KIHBARA") cout<<"YES"<<endl;
  	else cout<<"NO"<<endl;
}
