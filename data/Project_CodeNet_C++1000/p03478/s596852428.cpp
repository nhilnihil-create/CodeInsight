#include <bits/stdc++.h>
using namespace std;

int ai(int i){//十進数の合計を求める関数
    int j = i;//iのコピー
    int l = 0;
    int m = 0;// 十進数の合計 int n = 0;
    int n = 0;
    int k = 0;//桁数
    int b = 0;
    while(j != 0){
        j = j / 10;
        k++;
    }
    for(int a = 10;b < k;a *= 10){
        b++;
        if(a == 10){
        l = i % a;
        m += l;
        continue;
        }
        l = i % a;
        n = (l - (l % (a / 10))) / (a / 10);
        m += n;
    }
    return m;
}

int main(){
  int N,A,B;
  cin>>N>>A>>B;
  int l = 0;
  vector<int> a = {};//総和を求めるやつ
  for(int i = 1;i <= N;i++){
      int b = ai(i);
      if(A <= b){
          if(b <= B){
            a.push_back(i);
          }
      }
    }
    for(int i = 0;i < a.size();i++){
        l += a.at(i);
    }
    cout<<l<<endl;
}