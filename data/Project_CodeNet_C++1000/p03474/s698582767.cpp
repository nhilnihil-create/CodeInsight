#include <bits/stdc++.h>


using namespace std;

#define ll long long

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   int a,b;
   cin >> a >> b;
   string s;
   cin >> s;
   int cnt=0;
   for(char c : s) {
	   if(c=='-') {
		   cnt++;
	   }
	   if(cnt>1) break;
   }
   if(cnt==1&&s[a]=='-') cout << "Yes";
   else cout << "No";
   return 0;
}


