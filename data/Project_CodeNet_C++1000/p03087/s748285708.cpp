#include <bits/stdc++.h>
using namespace std;


int main() {

    string target_s = "AC";

    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;


    //ACの数を保存するベクトルを作成する。
    vector<int> count_ac(n,0);
    int cnt=0;
    int pos = s.find(target_s);
     while(pos != string::npos){
       cnt++;
       count_ac.at(pos+1)=cnt;
       pos=s.find(target_s,pos+target_s.size());
     }

    int wk2=0;
     for(int i=0;i<n;i++){
       int wk=count_ac.at(i);
       if(wk != 0){
          wk2=wk;
       }else{
          count_ac.at(i)=wk2;
       }
     }


    for(int i=0;i<q;i++){
      int l,r;
      cin>>l>>r;
      l--;
      r--;
      cout<<count_ac.at(r)-count_ac.at(l)<<endl;
      
    }
 
    return 0;
}
