#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int h, w, n; cin >> h >> w >> n;
  bool ok = true;

  int sr, sc; cin >> sr >> sc;
  string s, t; cin >> s >> t;
  int ss[4], tt[4]; fill(ss, ss+4, 0); fill(tt, tt+4, 0);

  for(int i=0; i<n && ok; i++) {
    switch (s[i]) {
      case 'L': ss[0]++; break;
      case 'R': ss[1]++; break;
      case 'U': ss[2]++; break;
      case 'D': ss[3]++; break;
    }
    //for(int x:ss) cout << x << " "; cout << endl;
    
    int s1 = sc + tt[1] - ss[0], // attempt to go lef
    s2 = sc - tt[0] + ss[1], // r
    s3 = sr + tt[3] - ss[2], // u
    s4 = sr - tt[2] + ss[3]; // d

    if (s1 < 1 || s2 > w ||  s3 < 1 || s4 > h) {
      //cout << i << endl;
      /*
      cout << (s1 < 1) << " "\
        << (s2 > w) << " "\
        << (s3 < 1) << " "\
        << (s4 > h) << " "\
        << endl;*/
      ok = false;
    }
    
    switch (t[i]) {
      case 'L': if (s2-1 >=1) tt[0]++; break;
      case 'R': if (s1+1 <=w) tt[1]++; break;
      case 'U': if (s4-1 >=1) tt[2]++; break;
      case 'D': if (s3+1 <=h) tt[3]++; break;
    }
    //for(int x:tt) cout << x << " "; cout << endl;
  }
  cout << (ok?"YES":"NO") << endl;
}