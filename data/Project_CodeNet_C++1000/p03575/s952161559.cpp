#include<bits/stdc++.h>
using namespace std;
 
int parent[50 * 50 + 5];
int length[50 * 50 + 5];
 
void init();
int getroot(int n);
bool samegroup(int n, int m);
bool unite(int n, int m);
 
int main(){
  int N, M;//N:ノードの数　M:エッジの数
  cin >> N >> M;
  vector<int> a(M), b(M);//データ数はMで数値はNまでの範囲
  for ( int i = 0; i < M ; i++) cin >> a.at(i) >> b.at(i);
  int ans = 0; //ブリッジとなるエッジの数
  
  for ( int i = 0; i < M ; i++){
    init(); //parent[k] = length[k] = k で初期化
    
    for ( int j = 0; j < M ; j++){
      if ( j == i ) continue;
      unite ( a[j],b[j]); //入力した全aj,bj間をエッジで連結
    }
    
    int parent = getroot(1);
    bool ok = true;
    for ( int i = 1; i <= N; i++){
      if ( !samegroup(parent, i)){
        ok = false;
        break;
      }
    }
    if(!ok) ans++;
  }
  cout << ans << endl;
}
 
void init(){
for ( int i = 0; i < 50 * 50 + 5; i++){
  parent[i] = i;
  length[i] = i;
}
  return;
}
int getroot(int n){
  if ( parent[n] == n){
    return n;
  } else{
    return getroot(parent[n]);
  }
}
bool samegroup(int n, int m){
  int nroot = getroot(n);
  int mroot = getroot(m);
  if ( nroot == mroot){
    return true;
  } else{
    return false;
  }
}
bool unite(int n, int m){
  if (samegroup(n, m)){
    return false;
  } else{
    int nroot = getroot(n);
    int mroot = getroot(m);
    if (length[nroot] == length[mroot]){
      parent[nroot] = mroot;
      length[mroot]++;
    } else if (length[nroot] > length[mroot]){
      parent[mroot] = nroot;
    } else {
      parent[nroot] = mroot;
    }
    return true;
  }
}