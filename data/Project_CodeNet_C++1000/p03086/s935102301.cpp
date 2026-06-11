#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

bool isAGCT(char c){
  if(c=='A' || c =='G' || c =='C' || c == 'T'){
    return true;
  }
  return false;
}

int main(){
    string S;
    cin >> S;
    int maxsize = 0;
    int size = 0;
    rep(i,S.size()){
      if(isAGCT(S.at(i))){
        size++;
        if(size > maxsize){
          maxsize = size;
        }
      }else{
        size = 0;
      }
    }
    printl(maxsize);
}
