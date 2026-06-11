#include<bits/stdc++.h>

using namespace std;

int main() {

	string S;
	cin >> S;
   int a=0;
   for(int i=1;i<S.size();i++){
      if(S[i]=='0'&&S[i-1]=='0'){
         S[i]='1';
         a++;
      }
      else if(S[i]=='1'&&S[i-1]=='1'){
         S[i]='0';
         a++;
      }
   }
   cout<<a<<endl;
   return 0;
}

