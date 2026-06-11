#include <bits/stdc++.h>
using namespace std;
string str = "1974";
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	vector<char> a(4);
	for(auto &x : a)cin>>x;
	for(auto x : a){
        if(str.find(x) != -1){
            str.erase(str.find(x), 1);
        }
	}
	if(str == "")cout<<"YES\n";
	else cout<<"NO\n";
}
