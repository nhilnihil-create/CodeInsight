#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  // if encounter smol on x, decrease left x by 1 then set all right to 9. you have your answer.

  string s;
  cin >> s;

  if (s.size() == 1) {
    cout << s << endl;
  } else {
    bool all9 = true;

    for (int i = s.size()-1; i >= 1; --i) {
      if (s.at(i) != '9') {
        all9 = false;
	break;
      }
    }

    if (!all9) {
	    for (int i = 0; i < s.size(); ++i) {
	      char c = s.at(i);

	      if (c != '9') {
		if (i == 0) {
		  s.at(i) -= 1;
		  for (int j = i+1; j < s.size(); ++j) {
		    s.at(j) = '9';
		  }
		  break;
		} else {
		  s.at(i-1) -= 1;
		  for (int j = i; j < s.size(); ++j) {
		    s.at(j) = '9';
		  }
		  break;
		}
	      }
	    }

	    int sum = 0;
	    for (char c : s) {
	      sum += (c-'0');
	    }
	    cout << sum << endl;
    } else {
	    cout << s.at(0)-'0' + 9*(s.size()-1) << endl;
    }
  }
  return 0;
}
