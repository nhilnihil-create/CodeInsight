//問題URL
//http://abc077.contest.atcoder.jp/tasks/arc084_b

//解き方メモ
//下記tweet以降の会話参照
//https://twitter.com/turnJP/status/932964573899976705

#include<iostream>
#include<deque>
#include<set>
#include<algorithm>
using namespace std;

int main(){
  int k;

  //input
  cin >> k;

  //pair(探索対象（余り）,桁総和)のキュー
  deque<pair<int,int>> q;
  set<int> st;

  //幅優先探索
  int val = 1;
  int dsum = 1;
  
  //Kの倍数なら終了
  while (val%k != 0) {
    //余りが既出でないなら、キューに値を入れて探索継続
    if(st.count(val) == 0){
      //既出の余りとしてセットに追加
      st.insert(val);

      if(val%10 != 9){
	//+1（桁総和+1）をキュー末尾に追加。桁上がりする値なら追加しない。既出のため。
	q.push_back(make_pair((val+1)%k,dsum+1)); 
      }
      //*10（桁総和同じ）をキュー先頭に追加
      q.push_front(make_pair(val*10%k,dsum)); 
    }

    //next
    pair<int,int> p = q.front();
    q.pop_front();
    val = p.first;
    dsum = p.second;
  }

  cout << dsum << endl;
  
  return 0;
}
