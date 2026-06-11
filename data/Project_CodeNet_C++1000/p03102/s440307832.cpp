#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n,m,c;
  cin>>n>>m>>c;
  
  vector <int> b(m);
  rep(h,m)cin>>b[h];
  

  vector<vector<int>> data(n, vector<int>(m));
 
  // 入力 (2重ループを用いる)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> data.at(i).at(j);
    }
  }


  int count = 0;
	int source=0;
 
  for (int k = 0; k < n; k++) {
    	source=0;
      for (int l = 0; l < m; l++) {
		source+=b[l]*data.at(k).at(l);
         }
    if(source+c>0){
    	count++;
    }
    
  }
    cout<<count<<endl;
}
    