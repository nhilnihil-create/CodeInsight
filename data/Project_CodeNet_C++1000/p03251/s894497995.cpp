#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll const lmt = 2e5+6;


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