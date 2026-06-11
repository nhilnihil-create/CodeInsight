#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

string str;
string target = "keyence";

int main(){
	cin>>str;
	if(str == target){
		cout << "YES" << endl;
		return 0;
	}
	int n = str.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string S = "";
			for(int k=0;k<n;k++){
				//除くところの先頭i
				//除くところの末尾j	をきめてるので、
				//除いてないところを取り出してる
				if(i<=k && k<=j){
					continue;
				}
				else S.push_back(str[k]);
			}
			if(S == target){
				cout << ("YES") << endl;;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
}