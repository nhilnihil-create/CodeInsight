#include <bits/stdc++.h>
using namespace std;

int main(){
 int n,q; cin >> n >>q;

 string s;cin >> s;
 vector<int> mark(n,0);
 vector<int> ans(q);

 for(int i=1;i<n;i++){
    if(s[i]=='C' && s[i-1]=='A'){
      mark[i]++;
    }
   mark[i]+=mark[i-1];
 }

 for(int i=0;i<q;i++){
   int a,b; cin >> a >> b;
   a--;b--;
   ans[i]=mark[b]-mark[a];
 }

 for(int i=0;i<q;i++) cout << ans[i] << endl;


 //for(int i=0;i<n;i++)cout << mark[i] << endl;
}
