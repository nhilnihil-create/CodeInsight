#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int NMAX=100007;
vector<int> S(NMAX+1,0);
vector<int> A(NMAX,0);

bool judge_prime(int p){
  if(p <= 2){
    return(false);
  }
  for(int i=2;i<floor(sqrt(p))+1;i++){
    if(p%i == 0 || ((p+1)/2) % i == 0){
      return(false);
    }
  }
  return(true);
}   

void prime_like(){
  for(int i=2;i<NMAX;i++){
    if(judge_prime(i)){
      A.at(i) = 1;
    }
  }
}

void initialize(){
  for(int i=0;i<NMAX;i++){
    S.at(i+1) = S.at(i) + A.at(i);
  }
}

// 区間[left, right)の総和
int sum(int left, int right){
    return S.at(right) - S.at(left);
}

int main(){
    int Q;
    cin >> Q;
    prime_like();
    initialize();
    for(int i=0;i<Q;i++){
      int l,r;
      cin >> l >> r;
      cout << sum(l,r+1) << endl;
    }
    return(0);
}