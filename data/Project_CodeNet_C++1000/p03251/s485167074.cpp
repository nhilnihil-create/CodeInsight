#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
  int maxx, miny;
  int n,m;
  cin >> n >> m >> maxx >> miny;
  
  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    if(tmp > maxx){
      maxx = tmp;
    }
  }
  
  for(int i = 0; i < m; i++){
    int tmp;
    cin >> tmp;
    if(tmp < miny){
      miny = tmp;
    }
  }
  
  if(miny > maxx){
    cout << "No War" << endl;
  } else { 
    cout << "War" << endl;
  }
  
}
