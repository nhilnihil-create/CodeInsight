#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    cin >> d[i];  
  }
  
  int count = 0;
  while (!d.empty()) {
  	// 最後を取得して削除
	int v = d.back();
    d.pop_back();
 
    // 残りから同じものを探し削除
    d.erase(
      remove_if(
        d.begin(),
        d.end(),
        [&v](auto& element){return element == v;}
      ),
      d.end()
    );
    // 検討済みリストに追加 => 追加の代わりに検討した回数を利用した
    count++;
  }
  
  cout << count << endl;
}
