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
    int counter = 0;
    int all = 0;
    char prev = '1';
    int index;
  P hoge;
    for(int i = 0;i < n; i++){
        if(s[i] == '0'){
            if(prev == '1'){
                hoge.first = i;
            }
            counter++;
            all++;
          if(i == n-1){
            hoge.second = i;
            zero.push_back(hoge); 
          }
        }
        if(s[i] == '1' && prev == '0'){
            //zero.push_back(counter);
          hoge.second = i-1;
            zero.push_back(hoge); 
        }
        prev = s[i];
 
    }
    //sort(s.begin(),s.end(),greater<int>());
    int ans = -1;
    int basyo = 0;
    int nagasa = zero.size();
    int last = min(k,nagasa);
  //cout << "unchi" << nagasa << endl;
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
        //cout << "ssss"<<basyo << endl;
      }
        if(basyo+k-1 < nagasa-1){
            ans = max(ans,zero[basyo+k].first-i);
            //cout << zero[basyo+k].first-i << endl;
        }
        
        else{
            ans = max(ans,n-i);
            //cout << n-i << endl;
        }
    }
    cout << ans << endl;
  }
  return 0;
}