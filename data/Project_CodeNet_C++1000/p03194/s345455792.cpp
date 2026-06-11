#include <iostream>
#include <cmath>
using namespace std;

int main(){
  unsigned long long int n;
  unsigned long long int p;
  cin >> n >> p;
  if (n == 1) {cout << p; return 0;}
  //cout << p << endl;
  unsigned long long int ans = 1;
  unsigned long long int max = pow(p, 1.0/n)+0.5;
  //cout << max <<endl;
  //cout << 'x';
  bool* sosu;
  //sosu = new bool[max+1];
  //cout << 'a';
  //for (unsigned long long int i = 0; i < max+1; i++) sosu[i] = true;
  //cout << 'b';
  for (unsigned long long int i = 2; i < max+1; i++){
     // cout << sosu[i] << " ";
    //if (!sosu[i]) continue;
    //cout << i <<" " << sosu[i] << endl;
    //unsigned long long int mod = pow(i, n)+0.5;
    unsigned long long int check = p;
    bool hantei = true;
    //cout << 'c';
    for (unsigned long long int j = 0; j < n; j++){
      //cout << 'd';
      if(check%i == 0) check = check/i;
      else {hantei = false; break;}
    }
    if(hantei){
       ans = i;
    }
    //else {for(unsigned int k = 1; k<=(max/i); k++) sosu[k*i] = false;}
  }
  //delete[] sosu;
    cout << ans;
    return 0;
}
