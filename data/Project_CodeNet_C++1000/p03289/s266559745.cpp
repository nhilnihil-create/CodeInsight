#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
vector<char> Alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main()
{
  cout << fixed << setprecision(10);
  string S;
  cin >> S;
  int N = S.size();
  bool ans = true;
  if(S[0]!='A')
  {
    ans = false;
  }
  rep(i,26)
  {
    if(S[1]==Alphabet[i])
    {
      ans = false;
    }
    else if(S[N-1]==Alphabet[i])
    {
      ans = false;
    }
  }
  int count = 0;
  rep(i,N-2)
  {
    rep(j,26)
    {
    if(S[i+2]==alphabet[j])
    {
      continue;
    }
    else if(S[i+2]=='C')
    {
      count ++;
      break;
    }
    
    }
  }
  if(ans==true&&count==1)
  {
    cout << "AC" << endl;
  }
  else
  {
    cout << "WA" << endl;
  }
  
  return 0;
}
