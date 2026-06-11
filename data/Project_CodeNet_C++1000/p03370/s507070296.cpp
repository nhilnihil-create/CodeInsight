#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,ans=0,count=0;
  cin >> n >> x;
  vector<int> m(n);
  for(int i=0;i<n;i++){
    cin >> m[i];
    ans+=m[i];
    count++;
  }
  if(ans==x)
    cout << count << endl;
  else{
    sort(m.begin(),m.end());
    int d=(x-ans)/m[0];
    count+=d;
    cout << count << endl;
  }
}
