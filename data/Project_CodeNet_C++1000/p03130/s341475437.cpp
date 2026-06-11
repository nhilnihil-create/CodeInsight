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
  map<int, int> count;
  for(int i=0;i<3;i++){
  	int a, b;cin>>a>>b;
    count[a]++;count[b]++;
  }
  bool ans=true;
  for(auto itr=count.begin();itr!=count.end();itr++){
  	if(itr->second>=3)ans=false;
  }
  cout<<(ans?"YES":"NO")<<endl;
}
