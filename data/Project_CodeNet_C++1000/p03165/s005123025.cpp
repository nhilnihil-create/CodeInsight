#include <bits/stdc++.h>
using namespace std;

string LCS(string s, string t){
    int r=s.size(), c=t.size();
    vector<vector<int>> vec(r+1, vector<int>(c+1));
    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){
            if(i==0 || j==0) vec[i][j]=0;
            else if(s[i-1]==t[j-1]) vec[i][j]=vec[i-1][j-1]+1;
            else {
                vec[i][j] = max(vec[i-1][j], vec[i][j-1]);
            }
        }
    }
    string str="";
    while(r>=0 && c>=0){
        if(vec[r][c]==vec[r][c-1]) c--;
        else if(vec[r][c]==vec[r-1][c]) r--;
        else if(vec[r][c]-1 == vec[r-1][c-1]){
            str+=s[r-1];
            r--; 
            c--;
        }
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(){
  string s,t;
  cin>>s>>t;
  cout<<LCS(s, t);
  return 0;
}