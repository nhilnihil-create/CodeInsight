#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  char a[3];
  rep(i, 0, 3){
    cin >> a[i];
    if(a[i] == '1'){
      a[i] = '9';
    }
    else{
      a[i] = '1';
    }
  }
  
  rep(i, 0, 3){
    cout << a[i];
  }
}
      