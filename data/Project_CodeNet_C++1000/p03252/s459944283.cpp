#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    int len = s.size();
  vector<int>alfa1(26, 0);
  vector<int>alfa2(26, 0);
    bool ans = true;
    for (int i = 0; i < len; i++){
      int a1 = s[i] - 'a';
      int a2 = t[i] - 'a';
      alfa1[a1]++; 
      alfa2[a2]++;
      if(alfa1[a1] != alfa2[a2]){
            ans = false;
            break;
        }
    }
    if(!ans)cout << "No" << endl;
    else cout << "Yes" << endl;
}