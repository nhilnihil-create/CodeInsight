#include <iostream>
#include <string>
template<class T,class C> T min(T a,C b){ return ((a)<(T)(b) ? (a) : (T)(b)); }
using namespace std;
int main(){
  int i,n,result=50,tmp=0,a;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a;
    tmp = 0;
    while(a%2==0){
      a /= 2;
      tmp++;
    }
    result = min(result,tmp);
  }
  cout << result << endl;
  return 0;
}