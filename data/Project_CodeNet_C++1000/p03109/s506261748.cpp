#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define debug(x)      cerr << "L" << __LINE__ << ": " << #x << " = " << (x) << endl
#define debugvec(v)   rep(i, v.size()) cerr << "L" << __LINE__ << ": " << #v << "[" << i << "] = " << v[i] << endl;
#define debugvec2(v)  cerr << "L" << __LINE__ << ": " << #v << " = { "; rep(i, v.size()) cerr << v[i] << (i + 1 == v.size() ? "" : ", "); cerr << " }" << endl;
typedef long long ll;  /* 10^18 くらいまでいける */

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}

int main(){
  string s;
  cin >> s;
  
  auto separatedStr = split(s, '/');
  if (stoi(separatedStr[1]) > 4)
    cout << "TBD" << endl;
  else
    cout << "Heisei" << endl;

  return 0;
}