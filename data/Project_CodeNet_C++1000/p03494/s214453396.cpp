#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin>>n;
vector<int> A(n);
for (int i = 0; i < n; i++) {
  cin >> A.at(i);
}
int ans=0;
bool odd=true;
while(odd==true) {
    for(int i=0; i<n; i++){
    if(A[i]%2==1){
        odd=false;
     break;
    }
    }
    for(int i=0; i<n; i++){
   A[i]/=2;
    }
    ans++;
}
ans--;
cout<<ans<<endl;
}