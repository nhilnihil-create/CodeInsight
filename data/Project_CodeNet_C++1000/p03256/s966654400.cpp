#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

signed main(void){
  
  int N,M; cin >> N >> M;
  string s; cin >> s;
  vector<int> A(N,0); //頂点iに隣接するAの個数をa[i]に入れる
  vector<int> B(N,0);
  
  vector<set<int>> check(N);
  vector<vector<int>> to(N);
  
  for(int i = 0; i < M; i++){ 
    
    int a,b; cin >> a >> b; 
    a--; b--;
    
    if( a > b ){ swap(a,b);}
    
    if( check[a].find(b) != check[a].end() || check[b].find(a) != check[b].end()){ continue;} 
    //すでにa-b間を繋いだことがある
    
    to[a].push_back(b); 
    to[b].push_back(a);
    
    check[a].insert(b);
    check[b].insert(a);
    
    //見たことなければ新情報
    
    if( s[b] == 'A' ){ A[a]++;} else{ B[a]++;}
    if( s[a] == 'A' ){ A[b]++;} else{ B[b]++;}
  }
  
  queue<int> Q;
  
  int cnt = 0;
  vector<bool> marked(N,false); 
  //一度ダメになったらもう一度判定する必要はない
  
  for(int i = 0; i < N; i++){ 
    if( !(A[i] > 0 && B[i] > 0) ){
      Q.push(i);  marked[i] = true;cnt++;
    }
  }
  //初めから条件を満たさないものについてはドシドシqueueに入れる
  
  while(!Q.empty()){ 
    
    int p = Q.front(); Q.pop();
    
    for(auto q : to[p] ){ 
      if( q == p || marked[q] ){ continue;} //自分自身に伝搬させる必要はない　元からだめ
      
      if( s[p] == 'A' ){ 
        A[q]--;
      }
      else{ 
        B[q]--;
      }
      
      if( !(A[q] > 0 && B[q] > 0 ) ){ 
        
        Q.push(q); cnt++; marked[q] = true;
      }
      //ダメなら追加
    }//for-auto
  }//while
  
  if( cnt == N ){ cout << "No" << endl;}
  else{ cout <<"Yes" << endl;}
  
  return 0;
}
  
    
    