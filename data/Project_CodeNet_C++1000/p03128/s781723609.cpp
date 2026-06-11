#include<iostream>
#include<string>
#include <sstream>

using namespace std;

void chmax(string &a,string b){
  if(a.length() < b.length()) a = b;
  else if(a.length()==b.length() && a < b) a = b;
}

int main(){
  int N,M;
  string A[10];
  int AA[10];
  int B[10] = {100,2,5,5,4,5,6,3,7,6};
  string dp[111111] = "";
  dp[0] = " ";
  cin >> N >> M;
  int i,j;
  for(i=0;i<=M-1;i++)
    cin >> A[i];
  for(i=0;i<=M-1;i++){
    if(A[i]=="1") AA[i]=1;
    if(A[i]=="2") AA[i]=2;
    if(A[i]=="3") AA[i]=3;
    if(A[i]=="4") AA[i]=4;
    if(A[i]=="5") AA[i]=5;
    if(A[i]=="6") AA[i]=6;
    if(A[i]=="7") AA[i]=7;
    if(A[i]=="8") AA[i]=8;
    if(A[i]=="9") AA[i]=9;
    }
  for(i=1;i<=N;i++)
    for(j=0;j<=M-1;j++)
      if(i>=B[AA[j]] && dp[i-B[AA[j]]] != "") chmax(dp[i],dp[i-B[AA[j]]]+A[j]);
  cout << dp[N] << endl;
}