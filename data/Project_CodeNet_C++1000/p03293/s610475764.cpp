#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;

int main(){                  
   string a, b; cin >> a >> b;
   for(int i = 0; i < a.length()+69; i++){
    	if(a == b){
    		cout << "Yes" << endl;
    		return 0;
    	}
    	string temp = a.substr(0, a.length()-1);
    	string temp2 = ""; temp2 += a[a.length()-1];
    	temp2 += temp;
    	a = temp2; 
   }
   cout << "No" << endl;
	return 0;
}                  
