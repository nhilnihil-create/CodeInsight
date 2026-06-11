#include<iostream>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

string q[]={"Vacant","Male","Female"};


int main(){
  int n; cin >>n;
  int a=0,b=n-1;
  print(a); flush(cout);
  string s; cin >>s;
  if(s==q[0]) return 0;
  int aj=(s==q[1]);
  print(b); flush(cout);
  cin >>s;
  if(s==q[0]) return 0;
  int bj=(s==q[1]);
  while(1){
    int m=(a+b)/2;
    print(m); flush(cout);
    cin >>s;
    if(s==q[0]) return 0;
    int mj=(s==q[1]);
    if((m-a)%2==(mj+aj)%2){
      a=m; aj=mj;
    }else{
      b=m; bj=mj;
    }
  }
}
