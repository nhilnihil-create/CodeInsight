#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >>N;
    vector<string>vec(N);
    for(int i=0;i<N;i++){
        cin >>vec.at(i);
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(vec.at(i)==vec.at(j)){
                cout <<"No"<<endl;
                return 0;
            }
        }   
    }
    for(int i=0;i<N-1;i++){
        int a;
      a=vec.at(i).size();//最後の文字をとっている
      if(vec.at(i).at(a-1)!=vec.at(i+1).at(0)){
          //vec.at(i+1).at(0)最初の文字
          cout << "No"<<endl;
          return 0;
      }
    }
    cout <<"Yes"<<endl;
}