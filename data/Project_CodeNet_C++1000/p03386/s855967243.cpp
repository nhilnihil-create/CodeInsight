#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int a,b,k,n,cnt=0;
  cin >> a >> b >> k;
  n=2*k;
  vector<int>stock(n);
  if(a+k>=b){
    for(int i=a; i<=b; i++){
      cout << i << endl;
    }
  }
  else{
    for(int i=a; i<a+k; i++){
      stock.at(cnt)=i;
      cnt++;
    }
    for(int i=b; i>b-k; i--){
      stock.at(cnt)=i;
      cnt++;
    }
    sort(stock.begin(), stock.end());
    for(int i=0; i<n-1; i++){
      int j=i+1;
      if(stock.at(i)==stock.at(j)){
        stock.at(j)=1000000000;
        sort(stock.begin(),stock.end());
        n--;
      }
      cout << stock.at(i) << endl;
    }
    cout << stock.at(n-1) << endl;
  }
}
