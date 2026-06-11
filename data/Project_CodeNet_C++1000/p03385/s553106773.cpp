#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int f = 0, g = 0, h = 0;
  rep(i, 0, 3){
    char a;
    cin >> a;
    if(a == 'a') f++;
    else if(a == 'b') g++;
    else if(a == 'c') h++;
  }
  if(f == 1 && g == 1 && h == 1){
    cout << "Yes\n";
  }
  else{
    cout << "No\n";
  }
}
  
  