#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
  int N;
  cin >> N;
  set <string> W;
  bool ans = true;
  char c = '\0';
  for (int i = 0; i < N; i++) {
    string w;
    cin >> w;
    W.insert(w);
    if (c!='\0') {
      if (c!=w[0]) {
        ans = false;
      }
    }
    c = w[w.length()-1];
  }
  if (N > W.size()) ans = false;
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
