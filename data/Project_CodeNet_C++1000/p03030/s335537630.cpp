#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
#define SORT(s) sort((s).begin(),(s).end())

int main() {
	int n;
  	cin>>n;
  tuple<string,int,int> p[110];//tupleとかpairとかを使って複数の値をまとめて管理
  
  for(int i=0;i<n;i++){
    string s;
    int a;
    cin>>s>>a;
  	p[i]=make_tuple(s,-a,i);//make_tupleでtupleを生成
  }							//昇順出力で大きい順に出るように点数を-に変換			
  sort(p,p+n);//ソートする
  
 
  for(int j=0;j<n;j++){
    
    cout<<get<2>(p[j])+1<<endl;//三番目の値+１を出力する
  }
  
}