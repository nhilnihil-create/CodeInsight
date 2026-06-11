#include <iostream>
#include<vector>
using namespace std;
int N,A,B,C;
vector<int> v;

int dfs(int i,int a,int b, int c){
      if(i == N){
            if(a == 0 || b == 0 || c == 0){
                  return 1000000;
            }else{
                  return abs(A - a) + abs(B - b) + abs(C - c) - 30;
            }
      }
      
      vector<int> t(4);
      t[0] = dfs(i + 1,a,b,c);
      t[1] = dfs(i + 1,a + v[i],b,c) + 10;
      t[2] = dfs(i + 1,a,b + v[i],c) + 10;
      t[3] = dfs(i + 1,a,b,c + v[i]) + 10;
      return min(t[0],min(t[1],min(t[2],t[3])));
}
int main(void){
    cin >> N >> A >> B >> C;
    v.resize(N);
    for(int i = 0;i < N;i++){
          cin >> v[i];
    }
    cout << dfs(0,0,0,0);
}
