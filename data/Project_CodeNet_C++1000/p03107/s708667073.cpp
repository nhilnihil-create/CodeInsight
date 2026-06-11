#include<bits/stdc++.h>

using namespace std;

int main() {

string S;
cin>>S;
int a=0;
int b=0;
vector<int>x(2,0);
for(int i=0;i<S.size();i++){
   if(S[i]=='0'){
      x[0]++;
   }
   else if(S[i]=='1'){
      x[1]++;
   }

}
int c=min(x[0],x[1]);

cout<<c*2<<endl;

   return 0;
}




