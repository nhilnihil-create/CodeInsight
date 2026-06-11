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
	string s;cin>>s;
	int div;cin>>div;
	for(int i=0;i<(int)s.size();i++){
		if(i%div==0)cout<<s[i];
	}
	cout << endl;
}