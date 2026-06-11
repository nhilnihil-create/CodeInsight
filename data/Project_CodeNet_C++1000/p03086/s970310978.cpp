#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;

int main(){
  //入力
  string S;
  cin >> S;
  //処理
  string T="ACGT";
  
  int ans=0;//ATCG文字列の最大長
  int now=0;//今見ている文字列を末尾とするATCG文字列の最大長
 
 for(int i = 0; i <(int) S.size(); i++) { 
     bool isACGT=false;
       for(int j=0;j<(int)T.size();j++){
         if(S[i]==T[j]) isACGT=true;
          }
    
       if(!isACGT){
         now=0;
       } 
       else{
         //ATCG文字列の場合は、1を足す。
         now++;
         //最大値を更新する
         ans=max(now,ans);
       }          
   }
   cout<<ans<<endl;
  return 0;
}
