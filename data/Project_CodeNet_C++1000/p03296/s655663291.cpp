#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
cin>>N;
vector<int> a(N);
for(int i=0;i<N;i++) cin>>a[i];
int cl=99999;
int ans=0;
for(int i=0;i<N-1;i++){
  if(a[i]==a[i+1]){
    a[i+1]=cl;
    cl--;
    ans++;
  }
}
cout<<ans<<endl;
}
