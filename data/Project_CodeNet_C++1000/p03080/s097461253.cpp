#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<string>
#include<map>

using namespace std;
const int INF = 1<<30;
typedef long long int ll;

int main(){
  int n;cin>>n;
  string s;cin>>s;
  int count=0;
  for(int i=0;i<n;i++){
    count+=(s[i]=='R');
  }
  cout<<(n/2<count?"Yes":"No")<<endl;
}
