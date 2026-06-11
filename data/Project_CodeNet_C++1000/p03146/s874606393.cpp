#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int s;
  	cin>>s;
  
  map<int,bool>mp;//mpに、sの値とイエローカードを残す
  
  	int cnt=0;//こっちを1にしてもいいんだな
  
  while(0==0){//whileってこんな使い方あるんだな
    if(mp[s]==true){//イエローもらっててもう一回同じ値になったら終わり
    	break;
    }
    mp[s]=true;//sの値を格納してイエロー
    if(s%2==0){//sを直接動かす
    	s/=2;
    }
    else{
    	s=(3*s)+1;
    }
    cnt++;//回数を数える
   }
  cout << cnt+1 << endl;
}