#include <bits/stdc++.h>
#define P pair<int, int>
#define PP pair<char, P>

using namespace std;

int main(){
  int h, w, n, sr, sc;
  string s, t;
  map<char, char> oposite;
  oposite['L'] = 'R';
  oposite['R'] = 'L';
  oposite['U'] = 'D';
  oposite['D'] = 'U';
  cin >> h >> w >> n >> sr >> sc;
  cin >> s >> t;
  sr--;sc--;
  for(auto p: {PP('L', P(0, -1)), PP('R', P(0, 1)), PP('U', P(-1, 0)), PP('D', P(1, 0))}){
    char c=p.first;
    int dy=p.second.first;
    int dx=p.second.second;
    int cy=sr;
    int cx=sc;
    for(int i=0;i<n;i++){
      if(s[i]==c){
        cy+=dy;
        cx+=dx;
      }
      if(!(0<=cy&&cy<=h-1&&0<=cx&&cx<=w-1)){
        cout << "NO" << endl;
        return 0;
      }
      if(t[i]==oposite[c]){
        cy=max(0, min(h-1, cy-dy));
        cx=max(0, min(w-1, cx-dx));
      }
    }
  }
  cout << "YES" << endl;
}

