#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int main(){
  string s;
  cin>>s;
  s = s+'T'; 
  int x[2];
  cin>>x[0]>>x[1];
  unordered_set<int> can[2]; // candidates
  can[0].insert(0);
  can[1].insert(0);
  int dir = 0;
  for(int i=0;i<s.size();){
     int c=0;
     while(s[i+c]=='F') c++;
     unordered_set<int> tmp;
     for(auto cc:can[dir]){
        tmp.insert(cc+c);
        if(i>0) tmp.insert(cc-c);
     }
     can[dir] = tmp;
     i+=c+1;
     cerr<<c<<i<<dir<<endl;
     dir ^= 1;
  }
  if(can[0].find(x[0])!=can[0].end() && can[1].find(x[1])!=can[1].end() )
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}


    