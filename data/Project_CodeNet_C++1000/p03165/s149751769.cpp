    #include<bits/stdc++.h>
    using namespace std;
    #define maxl 3010
    typedef vector<int> vi;
    vector<vi> pos;
    string s,t,sol;
    int32_t memo[maxl][maxl];
    int td(int i, int j){
      if(i>=s.size() || j>=t.size()) return 0;
      if(memo[i][j]!=-1) return memo[i][j];
      if(pos[(int)s[i]].empty()) return memo[i][j]=td(i+1,j);
      if(lower_bound(pos[(int)s[i]].begin(),pos[(int)s[i]].end(),j)==pos[(int)s[i]].end()) return memo[i][j]=td(i+1,j);
      int k=*lower_bound(pos[(int)s[i]].begin(),pos[(int)s[i]].end(),j);
      if(k!=t.size()) return memo[i][j]=max(td(i+1,j),1+td(i+1,k+1));
      return memo[i][j]=td(i+1,j);
    }
    void backtrack(int i, int j){
      if(i>=s.size() || j>=t.size()) return;
      if(pos[(int)s[i]].empty() || lower_bound(pos[(int)s[i]].begin(),pos[(int)s[i]].end(),j)==pos[(int)s[i]].end()) {
        backtrack(i+1,j);
        return;}
      int k=*lower_bound(pos[(int)s[i]].begin(),pos[(int)s[i]].end(),j);
      if(k!=t.size()) {
        if(memo[i+1][j]>1+memo[i+1][k+1])
          backtrack(i+1,j);
        else{
          sol+=s[i];
          backtrack(i+1,k+1);
        }
        return;
      }
      backtrack(i+1,j);
      return;
    }
    int main(){
      //cout<<(int)'a'<<endl;
      pos.assign(130,vi());
      cin>>s>>t;
      for (size_t i = 0; i < t.size(); i++) {
        pos[(int)t[i]].push_back(i);
      }
      for (size_t i = 0; i <= s.size(); i++) {
        for (size_t j = 0; j <= t.size(); j++) {
          memo[i][j]=-1;
        }
      }
      td(0,0);
      backtrack(0,0);
      cout<<sol<<'\n';
      return 0;
    }