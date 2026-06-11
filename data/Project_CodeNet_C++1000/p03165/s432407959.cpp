#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e9
// Parent pointer's concept with 2d suffix dp
//dp[i][j] - till i-1th char and j-1th char - max lcs found
//p[i][j] - parent of dp[i][j] - so basically from which cell of dp I came to i,j
//going from i,j to i+1,j nd stuff not oworking out for me--> back to basics
string solnF(string& a,string& b){
	int n1 = a.length(),n2 = b.length();
	// cout<<endl<<a<<endl<<b<<endl;
	vector<vector<int> > dp(n1+1,vector<int>(n2+1,0));
	vector<vector< pair<int,int> > > p(n1+1,vector< pair<int,int> >(n2+1));
	// dp[0][0]
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
				p[i][j] = make_pair(i-1,j-1);
			}	
			else if(dp[i][j-1]>dp[i-1][j]){
				dp[i][j] = dp[i][j-1];
				p[i][j] = make_pair(i,j-1);
			}
			else{
				dp[i][j] = dp[i-1][j];
				p[i][j] = make_pair(i-1,j);
			}
			// cout<<i<<" "<<j<<" "<<dp[i][j]<<" - "<<p[i][j].first<<" "<<p[i][j].second<<endl;
		}
	}
	//dp[n1][n2] is length of lcs
	string str;
	pair<int,int> cur = make_pair(n1,n2);
	pair<int,int> prev = p[n1][n2];
	// int count = 50;
	while(cur.first&&cur.second){
		// cout<<"KK";
		// cout<<cur.first<<" "<<cur.second<<endl;
		// cout<<prev.first<<" "<<prev.second<<endl;
		if(cur == make_pair(prev.first+1,prev.second+1)){
			str.push_back(a[prev.first]);
		}
		cur = prev;
		prev = p[prev.first][prev.second];
		// count--;
	}
	reverse(str.begin(),str.end());
	return str;
}


int main(){
	string a,b;
	getline(cin,a,'\n');
	// cout<<"kk";
	getline(cin,b,'\n');
	// string s; 
	// while (getline(cin, s)) 
	// { 
	// 	if (s.empty()) 
	// 		break; 
	// 	cout << s << endl; 
	// } 
	// return 0; 
	// cin>>b;
	// for(int i=0;i<n;i++) cin>>w[i]>>v[i];
	cout<<solnF(a,b)<<endl;
}
