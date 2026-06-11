#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

//AKIBA
//
int main(){
  string S;
  cin >> S;

  string akiba = "AKIHABARA";
  string res = "NO";

  if(S.size() < 5 || S .size() > akiba.size())
  {
    cout << res << endl;
    return 0;
  }

  //Aを取り除く、取り入れるのパターンを全網羅

  string akibas[16];
  ll cnt = 0;
  
  akibas[cnt++] = "KIHBR";
  akibas[cnt++] = "AKIHBR";
  akibas[cnt++] = "KIHABR";
  akibas[cnt++] = "KIHBAR";
  akibas[cnt++] = "KIHBRA";
  akibas[cnt++] = "AKIHABR";
  akibas[cnt++] = "AKIHBAR";
  akibas[cnt++] = "AKIHBRA";
  akibas[cnt++] = "KIHABAR";
  akibas[cnt++] = "KIHABRA";
  akibas[cnt++] = "KIHBARA";
  akibas[cnt++] = "AKIHABAR";
  akibas[cnt++] = "AKIHBARA";
  akibas[cnt++] = "AKIHABRA";
  akibas[cnt++] = "KIHABARA";
  akibas[cnt++] = "AKIHABARA";

  REP(i,16)
  {
    if(akibas[i] == S)
    {
      res = "YES";
    }
  }

  cout << res << endl;

  return 0;
}

