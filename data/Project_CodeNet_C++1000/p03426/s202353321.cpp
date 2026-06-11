#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int H, W, D;  //行・列・間隔
vector<P> A(90010);  //A[i]: iの数値マスの座標
vector<long long> C(90010);  //魔力消費累積和
int Q;  //クエリ数
vector<P> LR(100010);  //各クエリ格納

void CumS(int d){
  for(int i = d+1; i <= H * W; i++)
    C[i] = C[i-d] +
                 abs(A[i].first - A[i-D].first) +
                 abs(A[i].second - A[i-D].second);
}

void Query(int q){
  for(int i = 0; i < q; i++){
    int r = LR[i].second; int l = LR[i].first;
    cout << C[r] - C[l] << endl;
  }
}


int main(){
  cin >> H >> W >> D;
 
  int a; 
  for(int i = 1; i <= H; i++){ for(int j = 1; j <= W; j++){ 
      cin >> a; A[a] = {i, j};  //数値aのマスの座標(i,j)
  }}

  cin >> Q;
  for(int i = 0; i < Q; i++) 
    cin >> LR[i].first >> LR[i].second;  //クエリ入力

  CumS(D);  //累積和の計算
  Query(Q); //各クエリに対する出力

  return 0;
}



