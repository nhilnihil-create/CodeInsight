#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
   ll k,ans = 0;
   string n;
   cin >> n;
   stack<char> a;
   a.push(n[0]);
   for(int i = 1; i < n.size() ; i ++){
   	if(a.size() > 0){
   	if(a.top() == '0' && n[i] == '1'){
   			ans += 2;
   			a.pop();
		}
		else if(a.top() == '1' && n[i]== '0'){
			ans += 2;
			a.pop();
		}
		else
		a.push(n[i]);
	}
	else
	a.push(n[i]);
   }
   cout << ans <<"\n";
}  