#include <bits/stdc++.h>
using namespace std;

int main() {
int N; cin >> N;
vector<int> t(N), x(N), y(N);
for (int i = 0; i < N; i++) {
   cin >> t[i] >> x[i] >> y[i];
}
for(int i=0;i<N;i++){
if((t[i]-t[i-1])%2!=(abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))%2||(abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))>(t[i]-t[i-1])||t[0]%2!=(abs(x[0])+abs(y[0]))%2||abs(x[0])+abs(y[0])>t[0]){
   cout<<"No"<<endl;
   return 0;
}
}    
cout<<"Yes"<<endl;
return 0; 
}

