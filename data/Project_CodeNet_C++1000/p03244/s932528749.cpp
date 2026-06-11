#include <iostream>
#include <map>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int v[n];
  rep(i, n)
    cin >> v[i];
  //ここまで入力

  //奇数番目と偶数番目に登場する数字のカウント
  map<int, int> odd, even;
  for(int i=0; i<n; i+=2)
    odd[v[i] ]++;
  for(int i=1; i<n; i+=2)
    even[v[i] ]++;

  //奇数番目と偶数番目の数のうち，最頻値を調べる
  int odd_max = v[0], even_max = v[1];
  for(auto m : odd)
    if(m.second > odd[odd_max] )
      odd_max = m.first;
  for(auto m : even)
    if(m.second > even[even_max] )
      even_max = m.first;

  //偶奇ともに登場する数字は1種類
  if(odd[odd_max] == n/2 && even[even_max] == n/2){
    //全ての数字が同じ
    if(v[0] == v[1])
      cout << n/2 << endl;
    //もとからジグザグ
    else
      cout << 0 << endl;
  }
  //それ以外
  else{
    //最頻値が同じときは，二番目の最頻値で考える
    if(odd_max == even_max){
      int odd_max2 = -1;
      for(auto m : odd)
	if(m.second > odd[odd_max2] && m.first != odd_max)
	  odd_max2 = m.first;
      int even_max2 = -1;
      for(auto  m : even)
	if(m.second > even[even_max2] && m.first != even_max)
	  even_max2 = m.first;
      if(odd[odd_max2] < even[even_max2] )
	cout << n/2-odd[odd_max] + n/2-even[even_max2] << endl;
      else
	cout << n/2-odd[odd_max2] + n/2-even[even_max] << endl;
      
    }
    //最頻値を考える
    else
      cout << n/2-odd[odd_max] + n/2-even[even_max] << endl;
  }
  
  return 0;
}
