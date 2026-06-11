#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  string s;cin>>s;
  int k=(int)s.size();
  int count=0;
  for(int i=0;i<k;i++){
  	count += (s[i]!='o');
  }
  cout<<(count>=8?"NO":"YES")<<endl;
}
