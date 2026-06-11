#include <iostream>
#include <string>
#include <map>

using namespace std;

long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

int main(int argc, char* argv[]) {
  int N, M;
  cin >> N >> M;

  string s, t;
  cin >> s >> t;

  long long x = lcm(s.size(), t.size());

  map<int, char> m;
  for (int i = 0; i < s.size(); ++i) {
    long long index = i * (x / N) + 1;
    m[index] = s[i];
  }

  for (int i = 0; i < t.size(); ++i) {
    long long index = i * (x / M) + 1;
    if (m.find(index) != m.end() && m[index] != t[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }

  cout << x << endl;


  return 0;
}