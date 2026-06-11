#include <bits/stdc++.h>
using namespace std;

string Ticket(string S, int N){
  if(S.size() == 1){
    if (stoi(S) == N) {
      return S;
    }
    return "";
  }
  
  int l = S.size();
  string Last = "";
  Last.push_back(S.at(l-1));
  string Sp = S.erase(l-1);
  string a = Ticket(Sp, N - stoi(Last));
  string b = Ticket(Sp, N + stoi(Last));

    if ( a.size() > 0 ){
      return Ticket(Sp, N - stoi(Last)) + "+" + Last;
    }
    else if ( b.size() > 0 ) {
      return Ticket(Sp, N + stoi(Last)) + "-" + Last;
    }

  return "";
}

int main() {
  string St;
  cin >> St;
  
  cout << Ticket(St,7) << "=7" << endl;
  
  return 0;
}
