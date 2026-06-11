#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
typedef pair<int,int> P;

int d[5];

int main(void){
	          int i;

	      	  cin.tie(0);  ios_base::sync_with_stdio(false);

	      	  string s;
	      	  cin >> s;

	      	  int n=s.size();

	      	  REP(i,n){
	      		  if(s[i]=='a') d[0]++;
	      		  if(s[i]=='b') d[1]++;
	      		  if(s[i]=='c') d[2]++;
	      	  }

	      	  if((d[0]==0 && d[1]==0) || (d[0]==0 && d[2]==0) || (d[1]==0 && d[2]==0)){
	      		  if(n==1) cout << "YES" << endl;
	      		  else cout << "NO" << endl;
	      	  }
	      	  else if((d[0]==0 && d[1]!=0 && d[2]!=0) || (d[1]==0 && d[2]!=0 && d[0]!=0) || (d[2]==0 && d[0]!=0 && d[1]!=0)){
	      		  if(n==2) cout << "YES" << endl;
	      		  else cout << "NO" << endl;
	      	  }else{
	      		  if(abs(d[0]-d[1])>=2 || abs(d[0]-d[2])>=2 || abs(d[1]-d[2])>=2) cout << "NO" << endl;
	      		  else cout << "YES" << endl;
	      	  }

	          return 0;
}
