#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;
 
int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<P>zero;
    char prev = '1';
    int index;
  P hoge;
    for(int i = 0;i < n; i++){
        if(s[i] == '0'){
            if(prev == '1'){
                hoge.first = i;
            }
          if(i == n-1){
            hoge.second = i;
            zero.push_back(hoge); 
          }
        }
        if(s[i] == '1' && prev == '0'){
          hoge.second = i-1;
            zero.push_back(hoge); 
        }
        prev = s[i];
 
    }
    int ans = -1;
    int basyo = 0;
    int nagasa = zero.size();
    int last = min(k,nagasa);
  if(!zero.size()){
    cout << n << endl;
    return 0;
  }
  else{
    for(int i = 0; i < n; i++){
        if(i > zero[basyo].second && basyo < nagasa-1){
            basyo = basyo+1;
        }
      if(i == 6){
      }
        if(basyo+k-1 < nagasa-1){
            ans = max(ans,zero[basyo+k].first-i);
        }
        
        else{
            ans = max(ans,n-i);
        }
    }
    cout << ans << endl;
  }
  return 0;
}