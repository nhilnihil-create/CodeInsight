#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	string s;
	int k;
	cin>>s>>k;
	priority_queue<char, vector<char>, greater<char>> head;
	map<char,bool> check;

	for(auto a:s){
		if(!check.count(a)){
			check[a]=true;
			head.push(a);
		}
	}

	set<string> hoge;

	for(int i=0;!head.empty() && i<5;i++){
		char H=head.top();
		head.pop();

		for(int j=0;j<s.size();j++){
			if(s.at(j)==H){
				for(int k=j;k<s.size() && k-j<5;k++){
					string sub=s.substr(j,k-j+1);
					hoge.insert(sub);
				}
			}
		}

		if(hoge.size()>=5) break;
	}

	auto it=hoge.begin();

	for(int i=1;i<k;i++) it++;

	cout<<*it<<endl;

	return 0;
}
