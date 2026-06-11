#include<iostream>
#include<vector>
using namespace std;

long long N,A,B,C,D,ans;
string S;
string S1,S2;
vector <string> V1,V2;

long long gcd(long long x,long long y){
  while(y>0){
    x%=y;
    swap(x,y);
  }
  return x;
}

void solve(){
  cin >> A >> B >> C >> D;
  if ((A-B)<0) {
    cout << "No" << endl;
    return;
  }
  else if ((A%B)>C) {
    cout << "No" << endl;
    return;
  }
  else if (D<B) {
    cout << "No" << endl;
    return;
  }

  else if (C>=B) {
    cout << "Yes" << endl;
    return;
  }

  long long g = gcd(D,B);
  long long x = g*((C-(A%B))/g+1)+(A%B);
  if (x>=B) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main(){
  cin >> N;
  for (int i=0;i<N;i++){solve();}
}
