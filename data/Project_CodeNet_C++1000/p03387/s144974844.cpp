#include<bits/stdc++.h>

using namespace std;

int main() {
vector<int>n(3);
for(int i=0;i<3;i++){
   cin>>n[i];
}
sort(n.begin(),n.end());
int a=0;
while(!(n[0]==n[1]&&n[1]==n[2])){
   if(n[1]==n[2]){
      n[0]+=2;
      a++;
   }
   else{
      n[0]++;
      n[1]++;
      a++;
   }
   sort(n.begin(), n.end());
}
cout<<a<<endl;
   return 0;
}



