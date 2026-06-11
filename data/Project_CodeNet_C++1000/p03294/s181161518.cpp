#include<bits/stdc++.h>

using namespace std;

int main() {
int N;
cin>>N;
vector<int>a(N);
for(int i=0;i<N;i++){
   cin>>a[i];
}
int x=0;
for(int j=0;j<N;j++){
   x+=(a[j]-1);
}
cout<<x<<endl;
   return 0;
}




