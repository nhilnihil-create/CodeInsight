#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

#define __ { \
	freopen("input.txt","r",stdin); \
	freopen("output.txt","w",stdout); \
}
#define _ { \
	ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
}

int main(){
   _;
   //__;
   map<int,vector<int> > m;
   for(int i=0;i<3;i++){
   	int a,b;cin>>a>>b;
    m[a].emplace_back(b);
    m[b].emplace_back(a);
   }
   vector<int> v(4);
   for(int i=0;i<4;i++)v[i]=i+1;
   	bool ok=1;
   	do{
   		for(int i=0;i<3;i++){
   			if(find(m[v[i]].begin(),m[v[i]].end(),v[i+1])==m[v[i]].end()){
                  break;
   			}
   			else if(i==2){cout<<"YES";return 0;}
   		}

   	}while(next_permutation(v.begin(),v.end()));
cout<<"NO";return 0;
}