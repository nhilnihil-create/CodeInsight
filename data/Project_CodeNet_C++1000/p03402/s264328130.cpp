#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  cout  << 100 << " " << 100 << endl;
  for(int i=0; i<49; i++){
    for(int j=0; j<100; j++){
      if(i%2==0 && j%2==0 && cnt<a-1){
        cout << ".";
        cnt++;
      }else{
        cout << "#";
      }
    }
    cout << endl;
  }
  for(int j=0; j<100; j++){
    cout << "#";
  }
  cout << endl;
  for(int j=0; j<100; j++){
    cout << ".";
  }
  cout << endl;
  cnt = 0;
  for(int i=0; i<49; i++){
    for(int j=0; j<100; j++){
      if(i%2==0 && j%2==0 && cnt<b-1){
        cout << "#";
        cnt++;
      }else{
        cout << ".";
      }
    }
    cout << endl;
  }
  return 0;
}
